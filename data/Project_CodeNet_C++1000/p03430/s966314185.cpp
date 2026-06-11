#include<bits/stdc++.h>
using namespace std;
string S;
int K, dp[300][300][300];
int dfs(int l,int r,int k){
  if(dp[l][r][k]!=-1)return dp[l][r][k];
  if(l>r)return dp[l][r][k]=0;
  if(l==r)return dp[l][r][k]=1;
  dp[l][r][k]=0;
  if(S[l]==S[r])dp[l][r][k]=dfs(l+1,r-1,k)+2;
  dp[l][r][k]=max(dp[l][r][k],dfs(l+1,r,k));
  dp[l][r][k]=max(dp[l][r][k],dfs(l,r-1,k));
  if(k>0)dp[l][r][k]=max(dp[l][r][k],dfs(l+1,r-1,k-1)+2);
  return dp[l][r][k];
}
int main(){
  for(int i=0;i<300;i++)for(int j=0;j<300;j++)for(int k=0;k<300;k++)dp[i][j][k]=-1;
  cin>>S>>K;
  cout<<dfs(0,S.length()-1,K)<<endl;
}