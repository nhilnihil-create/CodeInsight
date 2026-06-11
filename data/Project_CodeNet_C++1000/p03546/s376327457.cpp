#include<bits/stdc++.h>
using namespace std;
int main(){
  long H,W;cin>>H>>W;
  long dp[10][10];
  for(long i=0;i<10;i++)for(long j=0;j<10;j++){
    cin>>dp[i][j];
  }
  for(long k=0;k<10;k++)for(long i=0;i<10;i++)for(long j=0;j<10;j++){
    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
  }
  long ans=0;
  for(long i=0;i<H;i++)for(long j=0;j<W;j++){
    long c;cin>>c;
    if(c!=-1)ans+=dp[c][1];
  }
  cout<<ans<<endl;
}
/*

*/