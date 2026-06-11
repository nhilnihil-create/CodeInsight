#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  vector<int> x(n);
  rep(i, 0, n) cin >> x[i];

  vector<ll> acc_p(1, 0), acc_m(1, 0);
  bool zero = false;
  rep(i, 0, n) {
    if (x[i] > 0)
      acc_p.push_back(x[i]);
    if (x[i] == 0)
      zero = true;
  }

  repr(i, 0, n) {
    if (x[i] < 0)
      acc_m.push_back(-x[i]);
  }

  if (zero)
    k--;
  if (k == 0) {
    cout << 0 << endl;
    return 0;
  }

  ll ans = 1e18;
  rep(p, 0, k + 1) {
    int m = k - p;
    if (p >= (int)acc_p.size() || m >= (int)acc_m.size())
      continue;
    chmin(ans, acc_p[p] * 2 + acc_m[m]);
    chmin(ans, acc_p[p] + acc_m[m] * 2);
  }

  cout << ans << endl;
}
