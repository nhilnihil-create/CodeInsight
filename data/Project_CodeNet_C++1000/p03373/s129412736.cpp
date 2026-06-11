#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  int money = 2147483647;
  int maxp = max(x, y);
  for (int w = 0; w <= maxp; w++) {
    int u = x - w;
    u = max(0, u);
    int v = y - w;
    v = max(0, v);
    if (u + w >= x && v + w >= y) {
      money = min(money, a * u + b * v + c * 2 * w);
    }
  }

  cout << money << endl;
}