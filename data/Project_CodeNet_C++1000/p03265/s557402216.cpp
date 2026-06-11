#include <iostream>

using namespace std;

int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int x3 = y1 - y2 + x2, y3 = x2 - x1 + y2;
  int x4 = y2 - y3 + x3, y4 = x3 - x2 + y3;
  printf("%d %d %d %d", x3, y3, x4, y4);
}
