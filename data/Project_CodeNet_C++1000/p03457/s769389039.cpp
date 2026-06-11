#include <iostream>
#include <cmath>

int main() {
  int lt = 0; int lx = 0; int ly = 0;
  int ct = 0; int cx = 0; int cy = 0;

  int n;
  std::cin >> n;

  bool traverable = true;
  for( int i = 0; i < n; ++i ) {
    lt = ct; lx = cx; ly = cy;
    std::cin >> ct >> cx >> cy;

    const int dt = ct - lt;
    const int dx = std::abs(cx - lx);
    const int dy = std::abs(cy - ly);

    const bool enough_time = (dx + dy) <= dt;
    const bool just_time = ((dx + dy) % 2) == (dt % 2);

    if( !enough_time || !just_time ) {
      traverable = false;
      break;
    }
  }

  if( traverable ) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }
}