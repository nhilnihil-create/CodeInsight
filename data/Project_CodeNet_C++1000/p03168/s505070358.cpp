#ifdef ONLINE_JUDGE
  #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#endif

#include "bits/stdc++.h"
using namespace std;
#define int long long
#define ld long double

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); debug("%s time : %.4fs\n", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))

signed main() {
  #ifndef ONLINE_JUDGE
    ifstream cin("in");
  #endif
  ios_base::sync_with_stdio(0); cin.tie(0); // harris leung ioi gold calling it 18.09

  int n; cin >> n;
  ld v[n + 1];
  for (int i = 1; i <= n; i ++) cin >> v[i];
  ld dp1[n + 1][n + 1]; // dp1[i][j] means j heads in first i coins
  memset(dp1, -1, sizeof(dp1));
  dp1[0][0] = 1;
  for (int i = 1; i <= n; i ++) {
    dp1[i][0] = dp1[i - 1][0] * (1 - v[i]);
    dp1[i][i] = dp1[i - 1][i - 1] * v[i];
  }
  for (int i = 1; i <= n; i ++) {
    for (int j = 1; j < i; j ++) {
      dp1[i][j] = dp1[i - 1][j - 1] * v[i] + dp1[i - 1][j] * (1 - v[i]);
    }
  }
  ld ans = 0;
  for (int i = n; i > n - i; i --) {
    ans += dp1[n][i];
  }
  cout << setprecision(15) << fixed << ans << endl;
}