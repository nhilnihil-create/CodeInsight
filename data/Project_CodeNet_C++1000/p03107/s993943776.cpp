#include <bits/stdc++.h>
using namespace std;
using i64 = int_fast64_t;

#define INF (i64)(1e18)
#define MOD (i64)(1e9+7)
#define REP(i, n) for(i64 i = 0; i < (n); i++)
#define RREP(i, n) for(i64 i = (n)-1; i >= 0; i--)
#define RANGE(i, a, b) for(i64 i = (a); i < (b); i++)
#define RRANGE(i, a, b) for(i64 i = (b)-1; i >= (a); i--)
#define ALL(v) (v).begin(), (v).end()
#define SIZE(v) ((i64)(v).size())
template<class T> inline void chmax(T &a, const T &b) { if (a < b) a = b; }
template<class T> inline void chmin(T &a, const T &b) { if (a > b) a = b; }

int main() {
  string s;
  cin >> s;
  string t = "";
  int ans = 0;
  REP(i, SIZE(s)) {
    if (SIZE(t) == 0 || s[i] == t.back()) {
      t.push_back(s[i]);
    } else {
      t.pop_back();
      ans++;
    }
  }
  cout << ans * 2 << endl;

  return 0;
}
