#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

int main() {
  int n, k;
  cin >> n >> k;
  V<ll> x(n);
  rep(i, n) cin >> x[i];

  ll ans = 1e10;
  rep(i, n - k + 1) {
    ll l = x[i];
    ll r = x[i + k - 1];
    if (r < 0) {
      ans = min(ans, abs(l));
    } else if (l > 0) {
      ans = min(ans, abs(r));
    } else {
      ll a = min(abs(l), abs(r));
      ll b = max(abs(l), abs(r));
      ans = min(ans, 2 * a + b);
    }
  }
  cout << ans << endl;
}
