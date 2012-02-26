#ifndef TEMPER_TYPE_HID_H
#define TEMPER_TYPE_HID_H

#include "tempered.h"

/** The maximum length of the temperature report data. */
#define TEMPER_TYPE_HID_REPORT_MAX_LENGTH 8

/** Type-specific data for HID devices. */
struct temper_type_hid_data {
	/** Length in bytes of the HID report to send (report_data field). */
	int report_length;
	
	/** Data for the HID report to send to the device to read the sensor(s). */
	unsigned char report_data[TEMPER_TYPE_HID_REPORT_MAX_LENGTH];
	
	/** Offset in the response containing the high byte of the temperature. */
	int temperature_high_byte_offset;
	
	/** Offset in the response containing the low byte of the temperature. */
	int temperature_low_byte_offset;
	
	/** Whether or not this device has a humidity sensor. */
	bool has_humidity;
	
	/** Offset in the response containing the high byte of the humidity. */
	int humidity_high_byte_offset;
	
	/** Offset in the response containing the low byte of the humidity. */
	int humidity_low_byte_offset;
};

/** Method for opening HID devices. */
bool temper_type_hid_open( tempered_device* device );

/** Method for closing HID devices. */
void temper_type_hid_close( tempered_device* device );

/** Method for getting the temperature from HID devices. */
bool temper_type_hid_get_temperature( tempered_device* device, float* tempC );

#endif
