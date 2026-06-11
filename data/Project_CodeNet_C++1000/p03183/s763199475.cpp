#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll mod=1e9+7;
ll dp[1007][10009];
vector<vector<ll>> box;
vector<ll> v;
ll solve(int i,int w)
{
  if(w>10000)
  return 0;
  if(i==0)
    return (w<=box[i][1])?box[i][2]:0;//w<=s[i]
  if(dp[i][w]!=-1)
    return dp[i][w];
  ll ans=solve(i-1,w);
  if(box[i][1]>=w)
    ans=max(ans,box[i][2]+(solve(i-1,w+box[i][0])));
  return dp[i][w]=ans;
}
bool cmp(vector<ll>& a,vector<ll>& b)
{
  return (a[0]+a[1])>(b[0]+b[1]);
}
int main()
{
  memset(dp,-1,sizeof(dp));
  int n;
  cin>>n;
  box.resize(n,vector<ll>(3));// w and s
  for(int i=0;i<n;i++)
    cin>>box[i][0]>>box[i][1]>>box[i][2];
  sort(box.begin(),box.end(),cmp);
  cout<<solve(n-1,0)<<endl;
  return 0;
}
