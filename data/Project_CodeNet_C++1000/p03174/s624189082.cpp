#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int mod=pow(10,9)+7;
int dp[22][(1<<22)+9];
vector<vector<int>>adj;
int solve(int n,int idx,int mask){
  if(mask==(1<<n)-1)
    return 1;
  if(idx==n)return 0;
  if(dp[idx][mask]!=-1)return dp[idx][mask];
  int new_mask;
  int ans=0;
  for(int i=0;i<(int)adj[idx].size();i++){
    int j=adj[idx][i];
    if(mask &(1<<j))continue;
    new_mask=mask;
    new_mask |=(1<<j);
    ans+=solve(n,idx+1,new_mask);
    ans%=mod;
  }
  dp[idx][mask]=ans;
  return dp[idx][mask];
}
int main(){
  int n;
  cin>>n;
  int arr[n][n];
  adj.resize(n+1);
  //i-->man j-->woman
  for(ll i=0;i<n;i++){
    for(ll j=0;j<n;j++){
      cin>>arr[i][j];
      if(arr[i][j]==1)adj[i].push_back(j);
    }
  }
  memset(dp,-1,sizeof(dp));
  int idx=0;
  int mask=0;
  int ans=solve(n,idx,mask);
  cout<<ans<<endl;
}