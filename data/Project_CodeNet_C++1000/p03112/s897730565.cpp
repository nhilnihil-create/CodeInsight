#include <bits/stdc++.h>
using namespace std;
using i64 = int_fast64_t;

#define INF (i64)(1e18)
#define MOD (i64)(1e9+7)
#define REP(i, n) for(i64 i = 0; i < (n); i++)
#define RREP(i, n) for(i64 i = (n)-1; i >= 0; i--)
#define REPF(i, a, n) for(i64 i = a; i < (a)+(n); i++)
#define RREPF(i, a, n) for(i64 i = (a)+(n)-1; i >= (a); i--)
#define RANGE(i, a, b) for(i64 i = (a); i < (b); i++)
#define RRANGE(i, a, b) for(i64 i = (b)-1; i >= (a); i--)
#define ALL(v) (v).begin(), (v).end()
#define SIZE(v) ((i64)(v).size())
template<class T> inline void chmax(T &a, const T &b) { if (a < b) a = b; }
template<class T> inline void chmin(T &a, const T &b) { if (a > b) a = b; }

i64 binary_search(vector<i64> v, i64 value) {
  i64 ok = -1, ng = SIZE(v);
  while (abs(ok-ng) > 1) {
    i64 mid = (ok+ng)/2;
    if (v[mid] < value) ok = mid;
    else ng = mid;
  }
  return ok;
}

int main() {
  i64 a, b, q;
  cin >> a >> b >> q;
  vector<i64> s(a+2), t(b+2), x(q);
  s[0] = -INF; s[a+1] = INF;
  t[0] = -INF; t[b+1] = INF;
  REP(i, a) cin >> s.at(i+1);
  sort(ALL(s));
  REP(i, b) cin >> t.at(i+1);
  sort(ALL(t));
  REP(i, q) cin >> x.at(i);

  REP(i, q) {
    i64 ans = INF;
    REPF(si, upper_bound(ALL(s), x[i])-s.begin()-1, 2) {
      REPF(ti, upper_bound(ALL(t), s[si])-t.begin()-1, 2) {
        chmin(ans, abs(x[i]-s[si])+abs(s[si]-t[ti]));
        chmin(ans, abs(x[i]-t[ti])+abs(t[ti]-s[si]));
      }
    }
    REPF(ti, upper_bound(ALL(t), x[i])-t.begin()-1, 2) {
      REPF(si, upper_bound(ALL(s), t[ti])-s.begin()-1, 2) {
        chmin(ans, abs(x[i]-s[si])+abs(s[si]-t[ti]));
        chmin(ans, abs(x[i]-t[ti])+abs(t[ti]-s[si]));
      }
    }
    cout << ans << endl;
  }

  return 0;
}
