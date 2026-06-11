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

  int n;
  cin >> n;
  vector<vector<int>> f(n, vector<int>(10)), p(n, vector<int>(11));
  rep(i, 0, n) rep(j, 0, 10) cin >> f[i][j];
  rep(i, 0, n) rep(j, 0, 11) cin >> p[i][j];

  ll ans = -1e18;
  rep(i, 1, 1 << 10) {
    vector<int> v(n);
    rep(j, 0, 10) {
      if (i >> j & 1) {
        rep(k, 0, n) { v[k] += f[k][j]; }
      }
    }
    ll sumv = 0;
    rep(k, 0, n) { sumv += p[k][v[k]]; }
    chmax(ans, sumv);
  }

  cout << ans << endl;
}
