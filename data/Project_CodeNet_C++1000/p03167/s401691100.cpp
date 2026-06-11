#ifdef ONLINE_JUDGE
  #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#endif

#include "bits/stdc++.h"
using namespace std;
#define int long long

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); debug("%s time : %.4fs\n", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))

signed main() {
  #ifndef ONLINE_JUDGE
    ifstream cin("in");
  #endif
  ios_base::sync_with_stdio(0); cin.tie(0); // harris leung ioi gold calling it 18.09

  const int mod = 1e9 + 7;
  int a, b; cin >> a >> b;
  int grid[a][b]; for (int i = 0; i < a; i ++) for (int j = 0; j < b; j ++) {char x; cin >> x; grid[i][j] = x == '.';}
  int dp[a][b]; memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int i = 0; i < a; i ++) {
    for (int j = 0; j < b; j ++) {
      if (grid[i][j] == 0) continue;
      if (i > 0) dp[i][j] += dp[i - 1][j];
      if (j > 0) dp[i][j] += dp[i][j - 1];
      dp[i][j] %= mod;
    }
  }
  cout << dp[a - 1][b - 1] << endl;
}