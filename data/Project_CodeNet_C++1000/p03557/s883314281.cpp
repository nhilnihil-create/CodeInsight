#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  rep(i, n) cin >> c[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());
  ll ans = 0;
  rep(i, n) {
    ll t = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
    ll u = c.end() - upper_bound(c.begin(), c.end(), b[i]);
    ans += t * u;
  }
  cout << ans << endl;
  return 0;
}
