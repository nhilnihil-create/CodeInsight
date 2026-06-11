#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000007
using namespace std;


int main(){
  int n;
  cin >> n;
  int dp[n+1];
  rep(i,n+1)dp[i] = INF;
  dp[0] = 0;
  rep(i,n){
    dp[i+1] = min(dp[i+1],dp[i] + 1);
    for(int j=1;i+1 - pow(6,j) >= 0; j++){
      int tmp = pow(6,j);
      dp[i+1] = min(dp[i+1],dp[i+1-tmp] + 1);
    }
    for(int j=1;i+1 - pow(9,j) >= 0;j++){
      int tmp = pow(9,j);
      dp[i+1] = min(dp[i+1],dp[i+1-tmp] + 1);
    }
  }
  cout << dp[n] << endl;
  return 0;
}