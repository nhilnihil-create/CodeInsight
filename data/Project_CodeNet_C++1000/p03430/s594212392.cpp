#include<bits/stdc++.h>
using namespace std;
int64_t dp[310][310][310];
string s;int64_t K;
int main(){
cin>>s>>K;
  int64_t N=s.size();
  for(int i=0;i<N;i++)
    for(int j=0;j<=K;j++)
    dp[i][i][j]=1;
  for(int i=0;i<N-1;i++)
    if(s.at(i)==s.at(i+1))
      dp[i][i+1][0]=2;
  else
    dp[i][i+1][0]=1;
  for(int j=2;j<=N-1;j++)
    for(int i=0;i<N-j;i++){
    if(s.at(i)==s.at(i+j))
      dp[i][i+j][0]=2+dp[i+1][i+j-1][0];
      else
        dp[i][i+j][0]=max(dp[i+1][i+j][0],dp[i][i+j-1][0]);
    }for(int i=0;i<N-1;i++)
      for(int j=1;j<=K;j++)
      dp[i][i+1][j]=2;
  for(int k=1;k<=K;k++)
      for(int j=2;j<=N-1;j++)
        for(int i=0;i<N-j;i++){
        if(s.at(i)==s.at(i+j))
          dp[i][i+j][k]=2+dp[i+1][i+j-1][k];
          else
dp[i][i+j][k]=max(max(2+dp[i+1][i+j-1][k-1],dp[i][i+j-1][k]),dp[i+1][i+j][k]);
          
        }cout<<dp[0][N-1][K]<<endl;
  return 0;
}