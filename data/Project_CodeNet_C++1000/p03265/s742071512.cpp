#include <iostream>
#include <cstdio>

int main() {
  int x1, y1;
  std::cin >> x1 >> y1;
  int x2, y2;
  std::cin >> x2 >> y2;

  int x_offset = x2 - x1;
  int y_offset = y2 - y1;

  int x3 = x2 - y_offset, y3 = y2 + x_offset;
  int x4 = x1 - y_offset, y4 = y1 + x_offset;

  printf("%d %d %d %d\n", x3, y3, x4, y4);
  return 0;
}