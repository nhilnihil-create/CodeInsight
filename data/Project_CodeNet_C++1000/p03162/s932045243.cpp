#include<iostream>

using namespace std;

int dp[100010][3];
int a[100010][3];

int main(){
  int n;
  cin >> n;
  for(int i=0;i < n;i++)for(int j=0;j < 3;j++) cin >> a[i][j];
  
  for(int i=0;i < n;i++){
    for(int j=0;j < 3;j++){
      for(int k=0;k < 3;k++){
        if(j == k) continue;
        dp[i+1][k] = max(dp[i+1][k],dp[i][j]+a[i][k]);
      }
    }
  }
  int ans = 0;
  for(int i=0;i < 3;i++) ans = max(ans,dp[n][i]);
  cout << ans << endl;
  return 0;
}