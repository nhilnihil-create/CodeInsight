// 2020-08-28 20:05:58
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
int b = 0;
struct Cake {
  ll x, y, z;
  Cake(ll x_, ll y_, ll z_) : x(x_), y(y_), z(z_) {}
  ll score() const {
    ll res = 0;
    if ((b >> 0) & 1)
      res += x;
    else
      res -= x;
    if ((b >> 1) & 1)
      res += y;
    else
      res -= y;
    if ((b >> 2) & 1)
      res += z;
    else
      res -= z;
    return res;
  }
  bool operator<(const Cake& rhs) const { return score() < rhs.score(); }
};

void answer() {
  int n, m;
  cin >> n >> m;
  vector<Cake> cs;
  rep(i, n) {
    ll x, y, z;
    cin >> x >> y >> z;
    cs.emplace_back(x, y, z);
  }
  ll ans = 0;
  for (b = 0; b < 8; b++) {
    sort(ALL(cs));
    ll nx = 0, ny = 0, nz = 0;
    rep(i, m) {
      nx += cs[i].x;
      ny += cs[i].y;
      nz += cs[i].z;
    }
    chmax(ans, abs(nx) + abs(ny) + abs(nz));
  }
  cout << ans << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}