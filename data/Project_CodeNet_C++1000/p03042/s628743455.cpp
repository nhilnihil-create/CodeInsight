#include <iostream>

int main()
{
  int S;
  std::cin >> S;

  int up = S / 100;
  int down = S % 100;

  bool up_mm = false;
  bool down_mm = false;
  bool invalid = true;

  if(1 <= up && up <= 12) {
    up_mm = true;
  }

  if(1 <= down && down <= 12) {
    down_mm = true;
  }

  std::string ret = "NA";
  if(up_mm && down_mm) {
    ret = "AMBIGUOUS";
  } else if(up_mm) {
    ret = "MMYY";
  } else if(down_mm) {
    ret = "YYMM";
  }

  std::cout << ret << std::endl;
  return 0;
}
