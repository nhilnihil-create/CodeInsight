#include <iostream>
 
int main(int argc, char *argv[]) {
  int x1, y1, x2, y2;
  std::cin >> x1 >> y1 >> x2 >> y2;
  int x = x2, y = y2, dx = x2 - x1, dy = y2 - y1;
  for (int i = 0; i < 2; ++i) {
    std::swap(dx, dy);
    dx = -dx;
    x += dx;
    y += dy;
    std::cout << x << " " << y << std::endl;
  }
}