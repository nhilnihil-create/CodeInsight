#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll k, a, b;
  cin >> k >> a >> b;
  if (b - a <= 2) {
    cout << k + 1 << endl;
    return 0;
  }
  k -= a - 1;
  ll ans = a + (b - a) * (k / 2) + (k % 2 == 1 ? 1 : 0);
  cout << ans << endl;
  return 0;
}
