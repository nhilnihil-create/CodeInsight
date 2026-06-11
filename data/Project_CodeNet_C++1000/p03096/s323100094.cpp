#include <bits/stdc++.h>
using namespace std;

int c[(int)2e5];
long long dp[(int)2e5];
long long c_dp[(int)2e5];

int main() {
  int n;
  cin>>n;
  for (int i=0; i<n; i++) {
    cin>>c[i];
    --c[i];
  }
  for (int i=0; i<n; i++) {
    dp[i] = 0;
    c_dp[i] = 0;
  }
  long long mod = 1e9 + 7;
  dp[0] = 1;
  c_dp[c[0]] = 1;
  for (int i=1; i<n; i++) {
    if (c[i] == c[i-1]) {
      dp[i] = dp[i-1];
    } else {
      dp[i] = dp[i-1] + c_dp[c[i]];
      c_dp[c[i]] += dp[i-1];
      dp[i] %= mod;
      c_dp[c[i]] %= mod;
    }
  }
  cout<<dp[n-1]<<endl;
}