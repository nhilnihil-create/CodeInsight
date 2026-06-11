#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  x2 -= x1;
  y2 -= y1;

  int x3, y3, x4, y4;
  x4 = -y2;
  y4 = x2;
  x3 = x4 + x2;
  y3 = y4 + y2;

  x3 += x1;
  y3 += y1;
  x4 += x1;
  y4 += y1;
  cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
  return 0;
}