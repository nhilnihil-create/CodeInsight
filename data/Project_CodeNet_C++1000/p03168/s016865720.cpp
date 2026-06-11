#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  double p[3010];
  for(int i=0;i<N;i++){
    cin>>p[i];
  }
  double dp[3010][3010];
  dp[0][0]=1;
  for(int i=0;i<=N;i++){
    for(int j=0;j<=i;j++){
      dp[i+1][j]+=dp[i][j]*(1-p[i]);
      dp[i+1][j+1]+=dp[i][j]*(p[i]);
    }
  }
  double ans=0;
  for(int i=N;i>(N/2);i--){
    ans+=dp[N][i];
  }
  cout<<setprecision(10)<<ans<<endl;
  //cout<<dp[3][3]<<" "<<dp[3][2]<<" "<<dp[3][1]<<" "<<dp[3][0]<<endl;
  return 0;
}
