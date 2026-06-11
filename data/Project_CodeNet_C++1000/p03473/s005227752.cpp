#include <iostream>
 
int main() {
  const static int HOURS_OF_DAY = 24;
  int hour = 0;
  std::cin >> hour;
  int lastHours = HOURS_OF_DAY - hour + HOURS_OF_DAY;
  std::cout << lastHours << std::endl;
}