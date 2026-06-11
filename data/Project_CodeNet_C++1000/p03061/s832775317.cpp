// 2020-07-04 16:37:06
#include<bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
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
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }

void answer() {
  int n;
  cin >> n;
  vector<int> a(n), dpl(n+1), dpr(n+1);
  rep(i, n) cin >> a[i];
  dpl[1] = a[0];
  dpr[n-1] = a[n-1];
  REP(i, 1, n) {
    dpl[i+1] = __gcd(dpl[i], a[i]);
    dpr[n-i-1] = __gcd(dpr[n-i], a[n-i-1]);
  }
  int ans = 0;
  chmax(ans, dpr[1]);
  chmax(ans, dpl[n-1]);
  REP(i, 1, n-1) {
    chmax(ans, __gcd(dpl[i], dpr[i+1]));
  }
  cout << ans << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}