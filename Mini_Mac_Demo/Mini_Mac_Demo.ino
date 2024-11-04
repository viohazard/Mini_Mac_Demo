#include <Wire.h>
#include <Adafruit_SSD1306.h>

String name1 = "NAME 1";
String name2 = "NAME 2";

int displayWidth = 128;

//Make Sure Address is Correct
#define OLED_ADDRESS 0x3C
Adafruit_SSD1306 display(displayWidth, 64, &Wire, OLED_ADDRESS);

#define LOGO_HEIGHT   32
#define LOGO_WIDTH    32


static const uint8_t image_data_logo[128] = {
    // ████████████████████████████████
    // ████████████████████████████████
    // ████████████████████████████████
    // ████████████████████████████████
    // ████████████████████████████████
    // ████████████████████████████████
    // ██████████████████∙∙████████████
    // █████████████████∙∙∙████████████
    // ████████████████∙∙∙█████████████
    // ████████████████∙∙∙█████████████
    // ████████████████∙███████████████
    // ███████████∙∙∙∙██∙∙∙∙∙██████████
    // █████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙█████████
    // █████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙█████████
    // ████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████████
    // ████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████████
    // ████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████████
    // ████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████████
    // ████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████████
    // ████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙█████████
    // █████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████████
    // █████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████████
    // █████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙█████████
    // ██████████∙∙∙∙∙∙∙∙∙∙∙∙∙█████████
    // ███████████∙∙∙∙∙∙∙∙∙∙∙██████████
    // ████████████∙∙∙███∙∙∙███████████
    // ████████████████████████████████
    // ████████████████████████████████
    // ████████████████████████████████
    // ████████████████████████████████
    // ████████████████████████████████
    // ████████████████████████████████
    0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xcf, 0xff, 
    0xff, 0xff, 0x8f, 0xff, 
    0xff, 0xff, 0x1f, 0xff, 
    0xff, 0xff, 0x1f, 0xff, 
    0xff, 0xff, 0x7f, 0xff, 
    0xff, 0xe1, 0x83, 0xff, 
    0xff, 0x80, 0x01, 0xff, 
    0xff, 0x80, 0x01, 0xff, 
    0xff, 0x00, 0x03, 0xff, 
    0xff, 0x00, 0x03, 0xff, 
    0xff, 0x00, 0x03, 0xff, 
    0xff, 0x00, 0x03, 0xff, 
    0xff, 0x00, 0x03, 0xff, 
    0xff, 0x00, 0x01, 0xff, 
    0xff, 0x80, 0x00, 0xff, 
    0xff, 0x80, 0x00, 0xff, 
    0xff, 0x80, 0x01, 0xff, 
    0xff, 0xc0, 0x01, 0xff, 
    0xff, 0xe0, 0x03, 0xff, 
    0xff, 0xf1, 0xc7, 0xff, 
    0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff
};


void setup() {
  display.cp437(true);
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS);
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  flashingCursor(3);
  delay(1000);

  display.setCursor(0, 0);
  display.println("MacIntosh 1984");
  display.setCursor(0, 8);
  display.println("Copyright(C)1984-2016");
  display.setCursor(0, 16);
  display.println("Main Processor:Intel");
  display.display();
  delay(2000);

  display.setCursor(0, 40);
  display.println("<CPUID:00028A29>");
  display.setCursor(0, 48);
  display.setTextColor(BLACK, WHITE);
  display.println("Memory: 2033MB OK");
  display.display();
  delay(4000);

  display.clearDisplay();
  display.drawBitmap(48,10,image_data_logo,32,32,1);    //accepts the following arguments (x, y, image array, image width, image height, rotation)
  display.display();

  loadingBar(16, 48, 96);
  //delay(200);
  display.invertDisplay(true);
  delay(400);
  display.clearDisplay();
  display.invertDisplay(false);
  
  nameMessage(name1, name2);
}

void loop() {
}

void loadingBar(int x, int y, int length){
  for (int i = 0; i < length; i++){
    display.drawFastHLine(x, y, i, WHITE); //accepts the following arguments (x, y, length, color)
    display.display();
    delay(10);
  };
}

void flashingCursor(int flashes){
  for (int i = 0; i < flashes; i++) {
        display.setCursor(0, 0);
        display.print("_");
        display.display();
        delay(500); // Duration the cursor is displayed
        display.clearDisplay();
        display.display();
        delay(500); // Duration the cursor is cleared
  }
}

void nameMessage(String name1, String name2){
  int name1x = ((displayWidth - ((name1.length() * 10)+10)) / 2);
  int name2x = ((displayWidth - ((name2.length() * 10)+10)) / 2);

  display.setTextColor(WHITE);
  display.setTextSize(2);

  if (name1.length() == 0 || name2.length() == 0){ // Either string1 or string2 is empty
    display.setCursor(name1x, 14);
    display.println(name1);
    display.setCursor(name2x, 14);
    display.print(name2);
    display.setTextSize(1);
    display.setCursor(16, 50);
    display.printf("%cCONGRATULATIONS%c", 0x03, 0x03);
    display.display();
  } else{ // Neither string1 nor string2 is empty
    display.setCursor(name1x, 0);
    display.println(name1);
    display.setCursor(61, 14);
    display.print("+");
    display.setCursor(name2x, 28);
    display.print(name2);
    display.setTextSize(1);
    display.setCursor(16, 50);
    display.printf("%cCONGRATULATIONS%c", 0x03, 0x03);
    display.display();
  }
}
