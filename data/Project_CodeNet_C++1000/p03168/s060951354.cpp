#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main() {
  int n;
  cin>>n;
  vector<double> p(n);
  for (int i=0;i<n;i++) cin>>p[i];
  vector<vector<double>> dp(n+1,vector<double>(n+1,0));
  
  dp[1][0] = 1-p[0];
  dp[1][1] = p[0];
  for (int i=2;i<=n;i++) {
    dp[i][0] = dp[i-1][0] * (1-p[i-1]);
    for (int j=1;j<=i;j++) {
      dp[i][j] = dp[i-1][j-1]*p[i-1] + dp[i-1][j]*(1-p[i-1]);
    }
  }
  double result = 0;
  for (int j=n;j>n/2;j--) result += dp[n][j];
  cout<<setprecision(10)<<result;
  
  return 0;
}
	