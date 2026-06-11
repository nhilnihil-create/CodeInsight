#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, m, n) for (int i = m; i < n; ++i)
const int MOD = 1000000007;

int main() {
  int N;
  cin >> N;
  vector<int> a(N), b(N);
  rep(i, 0, N) cin >> a[i];
  rep(i, 0, N) cin >> b[i];
  int ans = 0;
  for (int dig = 29; dig > -1; dig--) {
    int high = 1 << (dig + 1);
    int low = 1 << dig;
    rep(i, 0, N) a[i] %= high;
    rep(i, 0, N) b[i] %= high;
    sort(b.begin(), b.end());
    ll num = 0;
    rep(i, 0, N) {
      int add = 0;
      if (low - a[i] >= 0) {
        add += lower_bound(b.begin(), b.end(), high - a[i]) -
               lower_bound(b.begin(), b.end(), low - a[i]);
      } else {
        add += lower_bound(b.begin(), b.end(), high - a[i]) - b.begin();
        add += lower_bound(b.begin(), b.end(), high) -
               lower_bound(b.begin(), b.end(), high + low - a[i]);
      }
      num += add;
    }
    if (num & 1) ans += low;
  }
  cout << ans << endl;
  return 0;
}
