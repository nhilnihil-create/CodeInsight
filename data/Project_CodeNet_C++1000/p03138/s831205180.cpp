#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint INF = 1e18;

signed main(){
  lint N, K; cin >> N >> K;
  vector<lint> a(N);
  for(int i = 0; i < N; i++) cin >> a[i];
  vector<vector<lint> > dp(50, vector<lint> (2, -1));
  dp[40][0] = 0;
  for(lint d = 39; d >= 0; d--){
    lint mask = (1LL << d), num = 0;
    for(lint i = 0; i < N; i++) if(mask & a[i]) num++;
    if(dp[d + 1][1] != -1) dp[d][1] = max(dp[d][1], dp[d + 1][1] + mask * max(num, N - num));
    if(dp[d + 1][0] != -1){
      if(K & mask){
        dp[d][1] = max(dp[d][1], dp[d + 1][0] + mask * num);
        dp[d][0] = max(dp[d][0], dp[d + 1][0] + mask * (N - num));
      }
      else{
        dp[d][0] = max(dp[d][0], dp[d + 1][0] + mask * num);
      }
    }
  }
  cout << max(dp[0][0], dp[0][1]) << endl;
}