#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
  int n,k;
  cin>>n>>k;
  std::vector<int>V(n);
  for(int i =0;i<n;i++){
      cin>>V[i];
  }
  vector<vector<int> > dp(k+1,vector<int>(2));
  dp[0][0] = 1;
  dp[0][1] = 0;
  if(V[0]!=1){
      dp[1][0] = 1;
      dp[0][1] = 0;
  }
  else{
      dp[1][0] = 0;
      dp[1][1] = 1;
  }
  for(int i =2; i<=k;i++){
      dp[i][0] = 1;
      dp[i][1] =0;
      for(int j = 0;j<n;j++){
          if(i>=V[j]){
          dp[i][0] = min(dp[i][0],dp[i-V[j]][1]);
          dp[i][1] = max(dp[i][1],dp[i-V[j]][0]);
          }
      }
  }
  string ans;
  if(dp[k][1]==1){
      ans = "First";
  }
  else{
      ans = "Second";
  }
  //cout<<dp[5][1]<<dp[3][0]<<dp[2][0];
  //for(int i=0;i<=k;i++){
    //cout<<dp[i][0]<<dp[i][1]<<"\n";
  //}
  std::cout << ans << std::endl;
  return 0;
}