// 2020-08-28 16:52:33
// clang-format off
#include<bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define rep(i, n) REP(i, 0, (n))
#define repc(i, n) REPC(i, 0, (n))
#define REP(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define REPC(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
using namespace std;
using ll = long long;
using ld = long double;
using pr = pair<ll, ll>;
using vll = vector<ll>;
using vpr = vector<pr>;
using P = pair<ll, ll>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }

// clang-format on
int sum[60][60];
void answer() {
  int n, k;
  cin >> n >> k;
  vector<P> ps(n);
  map<ll, int> mx, my;
  rep(i, n) {
    ll x, y;
    cin >> x >> y;
    ps[i] = P(x, y);
    mx[x] = 0;
    my[y] = 0;
  }
  vector<ll> xs, ys;
  for (auto& m : mx) {
    xs.push_back(m.first);
    m.second = xs.size();
  }
  for (auto& m : my) {
    ys.push_back(m.first);
    m.second = ys.size();
  }
  for (auto& p : ps) {
    sum[mx[p.first]][my[p.second]] = 1;
  }
  rep(i, n) rep(j, n) {
    sum[i + 1][j + 1] += sum[i + 1][j] + sum[i][j + 1] - sum[i][j];
  }
  ll ans = 5e18;
  REP(i1, 1, n) REPC(i2, i1 + 1, n) REP(j1, 1, n) REPC(j2, j1 + 1, n) {
    int c =
        sum[i2][j2] - sum[i2][j1 - 1] - sum[i1 - 1][j2] + sum[i1 - 1][j1 - 1];
    if (c >= k) {
      ll now = (xs[i2 - 1] - xs[i1 - 1]) * (ys[j2 - 1] - ys[j1 - 1]);
      chmin(ans, now);
    }
  }
  cout << ans << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}