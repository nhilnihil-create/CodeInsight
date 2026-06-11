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
    s += '$';
    string t;
    rep(i, s.size()) {
      if(s[i] == 'B' && s[i+1] == 'C') t += 'D', i += 1;
      else t += s[i];
    }
    ll a = 0, ans = 0;
    rep(i, t.size()) {
      if(t[i] == 'A') a++;
      else if(t[i] == 'D') ans += a;
      else a = 0;
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