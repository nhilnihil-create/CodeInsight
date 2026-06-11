#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main() 
{
 
  ios::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);
 
  int n;
  cin >> n;

  int dp[n + 1];
  for(int i = 1; i <= n; i++)
      dp[i] = 1e9;

  dp[0] = 0;
  
  for(int i = 0; i <= n; i++){
     dp[i + 1] = min(dp[i + 1], dp[i] + 1);
      for(int j = 6; i + j <= n; j *= 6)
          dp[i + j] = min(dp[i + j], 1 + dp[i]);

      for(int j = 9; i + j <= n; j *= 9)
          dp[i + j] = min(dp[i + j], 1 + dp[i]); 
  }

  cout << dp[n];

  return 0;
}