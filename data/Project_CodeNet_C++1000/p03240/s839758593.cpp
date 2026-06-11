// 2020-08-31 19:01:03
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
  int n;
  cin >> n;
  vector<int> x(n), y(n), h(n);
  int mx = -1, my = -1, mh = -1;
  rep(i, n) {
    cin >> x[i] >> y[i] >> h[i];
    if (chmax(mh, h[i])) {
      mx = x[i];
      my = y[i];
    }
  }
  repc(cx, 100) repc(cy, 100) {
    int ch = mh + abs(cx - mx) + abs(cy - my);
    chmax(ch, 1);
    bool ok = true;
    rep(i, n) {
      int dh = ch - abs(cx - x[i]) - abs(cy - y[i]);
      chmax(dh, 0);
      if (dh != h[i]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << cx << ' ' << cy << ' ' << ch << '\n';
      return;
    }
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}