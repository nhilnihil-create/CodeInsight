#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

int main() {
  ll n;
  cin >> n;

  V<int> a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) b[i] = abs(a[i]);

  rep(i, n - 1) {
    if (a[i] < 0) {
      a[i] = -1 * a[i];
      a[i + 1] = -1 * a[i + 1];
    }
  }
  ll ans = 0;
  rep(i, n) ans += b[i];

  auto z = find(a.begin(), a.end(), 0);
  if (a.back() < 0 && z == a.end()) {
    auto m = minmax_element(b.begin(), b.end());
    ans -= *m.first * 2;
  }
  cout << ans << endl;
}
