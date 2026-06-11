#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

int main() {
  ll n, m;
  cin >> n >> m;

  ll ans = 1;
  for (ll i = 1; i * i <= m; i++) {
    if (m % i != 0) continue;
    if (i * n <= m) ans = max(ans, i);
    ll i2 = m / i;
    if (i2 * n <= m) ans = max(ans, i2);
  }

  cout << ans << endl;
}
