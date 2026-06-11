#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  string s;
  cin>>n>>s;
  int p=1000000007;
  vector<vector<int>> dp(n,vector<int>(n,0));
  vector<vector<int>> dps(n,vector<int>(n+1,0));
  dp[0][0]=1;
  dps[0][1]=1;
  for(int i=1;i<n;i++){
    for(int j=0;j<=i;j++){
      dp[i][j]=(s.at(i-1)=='<'?dps[i-1][j]:dps[i-1][i]-dps[i-1][j]+p)%p;
      dps[i][j+1]=(dps[i][j]+dp[i][j])%p;
    }
  }
  cout<<dps[n-1][n]<<endl;
}