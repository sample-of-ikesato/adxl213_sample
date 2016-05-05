#include <stdio.h>
#include "accel.h"


void accel_pin_state_changed(Accel *accel, unsigned char pin_state, unsigned short now)
{
  if (accel->last_pin_state != pin_state) {
    accel->last_pin_state = pin_state;
    if (accel->last_pin_state == 0) {
      if (accel->last_time < now)
        accel->on = now - accel->last_time;
      else
        accel->on = 65536 - (accel->last_time - now);
    } else {
      if (accel->last_time < now)
        accel->off = now - accel->last_time;
      else
        accel->off = 65536 - (accel->last_time - now);
    }
    accel->last_time = now;
  }
}
