#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;//aピザx枚、bピザy枚以上ほしい
  int kaikei = 2000000000;
  if (a + b <= 2 * c) kaikei = a * x + b * y;
  else {
    int minXorY = min(x, y);
    int maxXorY = max(x, y);
    int AorB = x > y? a: b;
    kaikei = min(2 * maxXorY * c, 2 * minXorY * c + (maxXorY - minXorY) * AorB);
  }
  cout << kaikei;
}