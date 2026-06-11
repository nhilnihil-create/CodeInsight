#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll k, a, b;
  cin >> k >> a >> b;
  if (k <= a || a + 2 >= b) {
    cout << k + 1 << '\n';
    return 0;
  }
  ll ans = a + (k - a + 1) / 2 * (b - a);
  if ((k - a + 1) % 2 == 1) ans++;
  cout << ans << '\n';
  return 0;
}
