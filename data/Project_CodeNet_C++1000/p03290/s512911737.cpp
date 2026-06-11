// 2020-08-25 23:21:21
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
  ll d, g;
  cin >> d >> g;
  vector<ll> p(d), c(d);
  rep(i, d) cin >> p[i] >> c[i];
  ll ans = 100000;
  rep(i, 1 << d) {
    ll rem = g, now = 0;
    rep(j, d) if ((i >> j) & 1) {
      rem -= p[j] * 100 * (j + 1) + c[j];
      now += p[j];
    }
    REPCM(j, d - 1, 0) {
      if (!((i >> j) & 1)) {
        rep(_, p[j]) {
          if (rem > 0) {
            now++;
            rem -= 100 * (j + 1);
          }
        }
      }
    }
    chmin(ans, now);
  }
  cout << ans << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}