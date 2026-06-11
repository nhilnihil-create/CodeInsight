// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
//  cout.precision(15); cout << fixed;

int main() {
  int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
  int dx = x2-x1;
  int dy = (y2-y1) * -1;
  swap(dx, dy);
  int x3 = x2+dx, y3 = y2+dy;
  int x4 = x1+dx, y4 = y1+dy;
  cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
  return 0;
}
