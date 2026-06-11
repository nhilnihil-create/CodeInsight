#include <bits/stdc++.h>
using namespace std;
int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int dx = (x2 - x1), dy = (y2 - y1);
  if (dx <= 0 && dy >= 0) {
    int x3 = x2 - abs(dy), y3 = y2 - abs(dx), x4 = x1 - abs(dy), y4 = y1 - abs(dx);
    printf("%d %d %d %d", x3, y3, x4, y4);
  }else if (dx <= 0 && dy <= 0) {
    int x3 = x2 + abs(dy), y3 = y2 - abs(dx), x4 = x1 + abs(dy), y4 = y1 - abs(dx);
    printf("%d %d %d %d", x3, y3, x4, y4);
  }else if (dx >= 0 && dy <= 0) {
    int x3 = x2 + abs(dy), y3 = y2 + abs(dx), x4 = x1 + abs(dy), y4 = y1 + abs(dx);
    printf("%d %d %d %d", x3, y3, x4, y4);
  } else {
    int x3 = x2 - abs(dy), y3 = y2 + abs(dx), x4 = x1 - abs(dy), y4 = y1 + abs(dx);
    printf("%d %d %d %d", x3, y3, x4, y4);
  }
}
