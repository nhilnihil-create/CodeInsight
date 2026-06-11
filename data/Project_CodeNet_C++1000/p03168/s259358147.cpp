#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<double>prob(n);
  for(auto &i:prob)cin>>i;
  double dp[n+1][n+1];
  memset(dp,0,sizeof(dp));
  dp[0][0]=1;
  for(int i=1;i<=n;i++){
    dp[i][0]=dp[i-1][0]*(1-prob[i-1]);
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=i;j++){
      dp[i][j]=prob[i-1]*dp[i-1][j-1]+(1-prob[i-1])*dp[i-1][j];
    }
  }
  double answer=0;
  for(int i=n/2+1;i<=n;i++){
    answer+=dp[n][i];
  }
  // for(int i=0;i<=n;i++){
  //   for(int j=0;j<=n/2+1)
  // }
  cout<<setprecision(9)<<answer;
  cout<<endl;
}