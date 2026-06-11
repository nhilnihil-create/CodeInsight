#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  int min_total = 1 << 30;
  for (int i = 0; i <= 100000; i++) {
    int buy_a = max(0, x - i);
    int buy_b = max(0, y - i);
    int total = i * 2 * c + a * buy_a + b * buy_b;
    min_total = min(min_total, total);
  }

  cout << min_total << endl;
  return 0;
}