#include<bits/stdc++.h>

#ifdef _PRINTDEBUG
  #include "lib/printdebug.hpp"
#else
  #define printdebug(...) 1
#endif
#define MOD_1_000_000_007 (1000000007)
#define IINF (1<<28)
#define LINF (1LL<<60)
#define rep(i, n)      REP(i, 0, (n))
#define repc(i, n)     REPC(i, 0, (n))
#define REP(i, n, m)   for (int i = (int)(n); i <  (int)(m); i++)
#define REPC(i, n, m)  for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
#define yesno(cond)       YESNO((cond), "Yes", "No")
#define YESNO(cond, a, b) cout << ((cond) ? (a) : (b)) << "\n"

namespace solver {
  using namespace std;
  typedef long long ll;

  string s;

  void init() {
    cin >> s;
  }

  void solve() {
    ll a = 0;
    char past2 = 'D', past1 = 'D';
    ll ans = 0;
    rep(i, s.size()) {
      char cur = s[i];
      if(past1 == 'A' && cur == 'A') {
        a++;
        past2 = past1;
        past1 = cur;
      } else if(cur == 'A') {
        a = 1;
        past2 = past1;
        past1 = cur;
      } else if(past1 == 'A' && cur == 'B') {
        past2 = past1;
        past1 = cur;
      } else if(past2 == 'A' && past1 == 'B' && cur == 'C') {
        ans += a;
        past2 = 'C';
        past1 = 'A';
      } else {
        a = 0;
        past2 = past1;
        past1 = cur;
      }
    }
    cout << ans << "\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  solver::init();
  solver::solve();
  return 0;
}
