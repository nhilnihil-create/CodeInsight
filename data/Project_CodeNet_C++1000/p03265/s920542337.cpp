#include <iostream>

using namespace std;

int main(void) {
  int x1, x2, x3, x4, x;
  int y1, y2, y3, y4, y;
  cin >> x1 >> y1 >> x2 >> y2;
  x = x2 - x1;
  y = y2 - y1;
  x3 = x2 - y;
  y3 = y2 + x;
  x4 = x3 - x;
  y4 = y3 - y;
  printf("%d %d %d %d\n", x3, y3, x4, y4);
  return 0;
}