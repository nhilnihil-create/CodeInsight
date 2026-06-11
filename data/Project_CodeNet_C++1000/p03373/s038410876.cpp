#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  int ans = a * x + b * y;
  for (int i = 0; i <= max(x, y); i++) {
    int na = max(0, x - i);
    int nb = max(0, y - i);
    ans = min(ans, na * a + nb * b + 2 * i * c);
  }
  
  cout << ans << '\n';
  return 0;
}
