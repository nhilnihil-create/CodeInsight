/**
 *    author:  tourist
 *    created: 29.12.2019 23:00:19       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  b = min(b, 2 * c);
  a = min(a, 2 * c);
  long long ans = min(a + b, 2 * c) * min(x, y);
  ans += a * (x - min(x, y));
  ans += b * (y - min(x, y));
  cout << ans << '\n';
  return 0;
}
