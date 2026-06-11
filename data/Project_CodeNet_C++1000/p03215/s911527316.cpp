// 2020-09-11 23:24:32
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
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  vector<ll> b;
  rep(i, n) {
    ll cur = 0;
    REP(j, i, n) {
      cur += a[j];
      b.push_back(cur);
    }
  }
  sort(RALL(b));
  int bz = b.size();
  int c = -1;
  ll ans = -1;
  REPCM(i, 45, 0) {
    int tot = 0;
    rep(j, bz) if ((b[j] >> i) & 1) tot++;
    if (tot >= k) {
      c = i;
      ans = (1ll << i);
      break;
    }
  }
  REPCM(i, c - 1, 0) {
    int tot = 0;
    rep(j, bz) if (((b[j] & ans) == ans) && ((b[j] >> i) & 1)) tot++;
    if (tot >= k) ans |= (1ll << i);
  }
  cout << ans << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}