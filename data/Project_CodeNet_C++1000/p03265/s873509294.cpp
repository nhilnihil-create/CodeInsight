#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
  int dx = x2 - x1, dy = y2 - y1;
  int x3 = x2 - dy, y3 = y2 + dx;
  int x4 = x3 - dx, y4 = y3 - dy;
  cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
}
