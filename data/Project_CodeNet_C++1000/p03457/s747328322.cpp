#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int t = 0;
  int x = 0;
  int y = 0;
  bool flag = true;

  int t1, x1, y1;
  while (cin >> t1 >> x1 >> y1) {
    int dt = t1 - t;
    int dx = x1 - x;
    int dy = y1 - y;
    int cost = abs(dx) + abs(dy);
    if (dt < cost || (dt - cost) % 2 != 0)
      flag = false;
    t = t1;
    x = x1;
    y = y1;
  }

  cout << (flag ? "Yes" : "No") << endl;
}
