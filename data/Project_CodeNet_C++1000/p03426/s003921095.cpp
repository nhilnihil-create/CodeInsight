// 2020-08-30 17:28:30
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
using P = pair<int, int>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }

// clang-format on
void answer() {
  int h, w, d;
  cin >> h >> w >> d;
  vector<P> a(h * w + 10);
  rep(i, h) rep(j, w) {
    int x;
    cin >> x;
    a[x] = P(i, j);
  }
  vector<ll> dp(h * w + 10, 0);
  REPC(i, d + 1, h * w) {
    int j = i - d;
    dp[i] =
        dp[j] + abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second);
  }
  int q;
  cin >> q;
  rep(qi, q) {
    int l, r;
    cin >> l >> r;
    cout << dp[r] - dp[l] << '\n';
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}