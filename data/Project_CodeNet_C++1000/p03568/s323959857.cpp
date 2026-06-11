#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  vector<vector<int>> dp(n+1,vector<int>(2));
  dp[0][0]=1;
  for(int i=0;i<n;i++){
    if(a[i]%2==0){
      dp[i+1][0]=dp[i][0]*2;
      dp[i+1][1]=dp[i][1]*3+dp[i][0];
    }
    else{
      dp[i+1][0]=dp[i][0];
      dp[i+1][1]=dp[i][1]*3+dp[i][0]*2;
    }
  }
  cout << dp[n][1] << endl;
}