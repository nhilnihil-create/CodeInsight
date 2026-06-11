#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll minmm=pow(10,15)+7;
ll solve(ll prefsum[],ll arr[],vector<vector<ll>>&dp,ll start,ll end){
  if(start>end)return 0;
  if(start==end)return 0;
  if(end-start==1)return arr[start]+arr[end];
  if(dp[start][end]!=-1)return dp[start][end];
  ll minm=minmm;
  for(ll i=start;i<end;i++){
    ll sumf=prefsum[i+1]-prefsum[start];
    ll sums=prefsum[end+1]-prefsum[i+1];
    ll temp=solve(prefsum,arr,dp,start,i)+solve(prefsum,arr,dp,i+1,end)+sumf+sums;
    minm=min(minm,temp);
  }
  dp[start][end]=minm;
  return dp[start][end];
}
int main(){
  ll n;
  cin>>n;
  ll arr[n];
  ll prefsum[n+1];
  prefsum[0]=0;
  for(ll i=0;i<n;i++){
    cin>>arr[i];
    prefsum[i+1]=prefsum[i]+arr[i];
  }
  vector<vector<ll>>dp(n,vector<ll>(n,-1));
  ll start=0;
  ll end=n-1;
  ll ans=solve(prefsum,arr,dp,start,end);
  cout<<ans<<endl;
}