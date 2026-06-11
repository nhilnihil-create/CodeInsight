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

  int N, dp[20][100010];

  void init() {
    cin >> N;
  }

  void solve() {
    vector<int> coins = {1};
    int a = 6;
    while(a <= 100000) {
      coins.push_back(a);
      a *= 6;
    }
    a = 9;
    while(a <= 100000) {
      coins.push_back(a);
      a *= 9;
    }
    sort(coins.begin(), coins.end());
    coins.erase(unique(coins.begin(), coins.end()), coins.end());
    repc(j, N) dp[0][j] = IINF;
    dp[0][0] = 0;
    rep(i, coins.size()) repc(j, N) {
      dp[i+1][j] = dp[i][j];
      if(coins[i] <= j) dp[i+1][j] = min(dp[i+1][j], dp[i+1][j-coins[i]]+1);
    }
    cout << dp[coins.size()][N] << "\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  solver::init();
  solver::solve();
  return 0;
}