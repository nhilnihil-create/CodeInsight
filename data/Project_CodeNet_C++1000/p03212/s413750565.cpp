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

  int N, ans;

  void init() {
    cin >> N;
  }

  void rec(int n, int d, int three, int five, int seven, int last) {
    if(d > 8 || last == 0) {
      if (three && five && seven && 1 <= n && n <= N) {
        ans++;
      }
      return;
    }
    rec(n + 0 * pow(10, d), d+1, three+0, five+0, seven+0, 0);
    rec(n + 3 * pow(10, d), d+1, three+1, five+0, seven+0, 3);
    rec(n + 5 * pow(10, d), d+1, three+0, five+1, seven+0, 5);
    rec(n + 7 * pow(10, d), d+1, three+0, five+0, seven+1, 7);
  }

  void solve() {
    rec(0, 0, 0, 0, 0, -1);
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