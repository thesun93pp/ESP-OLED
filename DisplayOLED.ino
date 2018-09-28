
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET LED_BUILTIN  //4
Adafruit_SSD1306 display(OLED_RESET);


void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  // Clear the buffer.
  display.clearDisplay();
  display.display();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("starting....");
  display.display();

}
String cmd = "";
void loop() {
  while (Serial.available() > 0) {
    char c  = Serial.read();
    if (c == ';') {//end of command => display data;
      
      break;
    }
    cmd += c;
  }
}

void displayData(int sophuthengio, int sophutdanau) {
  display.clearDisplay();
  display.display();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  char displayData[100];
  snprintf ( displayData, 100,
             "Hen gio: %02d \r\nBat dau nau: %02d",
             sophuthengio, sophutdanau
           );

  display.println(displayData);
  display.display();
}
