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

  int N, P[110][20], F[110];

  void init() {
    cin >> N;
    bool f;
    rep(i, N) rep(j, 10) {
      cin >> f;
      F[i] |= (f << j);
    }
    rep(i, N) repc(j, 10) {
      cin >> P[i][j];
    }
  }

  void solve() {
    int a = 0;
    ll maxv = -LINF;
    REP(k, 1, 1<<10) {
      ll acc = 0;
      rep(i, N) {
        acc += P[i][__builtin_popcount(k & F[i])];
      }
      maxv = max(maxv, acc);
    }
    cout << maxv << "\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  solver::init();
  solver::solve();
  return 0;
}