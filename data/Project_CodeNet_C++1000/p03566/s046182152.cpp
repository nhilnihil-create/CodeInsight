// 2020-08-30 18:03:20
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
  vector<int> t(n), v(n);
  rep(i, n) {
    cin >> t[i];
    t[i] *= 2;
  }
  rep(i, n) {
    cin >> v[i];
    v[i] *= 10;
  }
  vector<int> vm(40040, 0);
  int ti = 0;
  {
    rep(i, n) {
      rep(j, t[i]) {
        int tj = ti + j + 1;
        vm[tj] = min(v[i], vm[tj - 1] + 5);
      }
      ti += t[i];
    }
  }
  vm[ti] = 0;
  {
    REPCM(i, n - 1, 0) {
      rep(j, t[i]) {
        int tj = ti - j - 1;
        chmin(vm[tj], min(v[i], vm[tj + 1] + 5));
      }
      ti -= t[i];
    }
  }
  ld ans = 0;
  rep(i, 40020) { ans += ld(vm[i] + vm[i + 1]) / ld(40); }
  cout << fixed << setprecision(15) << ans << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}