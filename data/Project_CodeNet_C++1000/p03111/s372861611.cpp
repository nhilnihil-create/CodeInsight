#include <bits/stdc++.h>
using namespace std;
using i64 = int_fast64_t;

#define INF ((i64)(1e18))
#define MOD ((i64)(1e9+7))
#define REP(i, n) for(i64 i = 0; i < (n); i++)
#define RREP(i, n) for(i64 i = (n)-1; i >= 0; i--)
#define RANGE(i, a, b) for(i64 i = (a); i < (b); i++)
#define RRANGE(i, a, b) for(i64 i = (b)-1; i >= (a); i--)
#define ALL(v) (v).begin(), (v).end()
#define SIZE(v) ((i64)(v).size())
template<class T> inline void chmax(T &a, const T &b) { if (a < b) a = b; }
template<class T> inline void chmin(T &a, const T &b) { if (a > b) a = b; }

i64 n, a, b, c;
vector<i64> l;

i64 dfs(vector<i64>::iterator it, i64 sa, i64 sb, i64 sc) {
  if (it == l.end()) {
    if (min({sa, sb, sc}) == 0) return INF;
    return abs(a-sa)+abs(b-sb)+abs(c-sc);
  }
  i64 val0 = dfs(it+1, sa, sb, sc);
  i64 val1 = dfs(it+1, *it+sa, sb, sc)+10;
  i64 val2 = dfs(it+1, sa, *it+sb, sc)+10;
  i64 val3 = dfs(it+1, sa, sb, *it+sc)+10;
  return min({val0, val1, val2, val3});
}

int main() {
  cin >> n >> a >> b >> c;
  l = vector<i64>(n);
  REP(i, n) cin >> l.at(i);

  cout << dfs(l.begin(), 0, 0, 0)-30 << endl;

  return 0;
}
