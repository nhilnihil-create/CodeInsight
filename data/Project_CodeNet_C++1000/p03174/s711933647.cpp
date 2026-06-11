#include<bits/stdc++.h>
using namespace std;
const long MOD = 1000000007;
int main(){
  int n;
  cin >> n;
  vector<vector<int>> a(n,vector<int> (n));
  for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> a[i][j];
  vector<vector<long>> dp(n+1,vector<long> (1<<n,0));
  dp[0][0]=1;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(a[i][j]==0) continue;
      for(int k=0;k<(1<<n);k++){
        dp[i+1][k|(1<<j)] += dp[i][k];
        dp[i+1][k|(1<<j)] %= MOD;
      }
    }
  }
  cout << dp[n][(1<<n)-1] << endl;
}