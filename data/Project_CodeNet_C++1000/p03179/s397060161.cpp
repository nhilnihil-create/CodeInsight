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

  int N;
  string S;
  ll dp[3030][3030], sum[3030][3030];

  void init() {
    cin >> N >> S;
  }

  ll rec(int i, int j) {
    if(dp[i][j] >= 0) return dp[i][j];
    if(i >= N) return dp[i][j] = 1;
    if(sum[i][0] == -1) {
      sum[i][0] = 0;
      REPC(k, 1, N-i) {
        sum[i][k] = (sum[i][k-1] + rec(i+1, k-1)) % MOD_1_000_000_007;
      }
    }
    int lower_n = j;
    int greater_n = N-i-j;
    char c = '<';
    if(i > 0) c = S[i-1];
    if(c == '>' && lower_n > 0) {
      return dp[i][j] = (sum[i][lower_n] + MOD_1_000_000_007 - sum[i][0]) % MOD_1_000_000_007;
    } else if(c == '<' && greater_n > 0) {
      return dp[i][j] = (sum[i][lower_n+greater_n] + MOD_1_000_000_007 - sum[i][lower_n]) % MOD_1_000_000_007;
    } else {
      return dp[i][j] = 0;
    }
  }

  void solve() {
    memset(dp, -1, sizeof dp);
    memset(sum, -1, sizeof sum);
    cout << rec(0, 0) << endl;
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  solver::init();
  solver::solve();
  return 0;
}