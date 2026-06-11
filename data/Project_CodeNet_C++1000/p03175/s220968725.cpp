#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=pow(10,9)+7;
//int dp[22][(1<<22)+9];
vector<vector<ll>>adj;
pair<ll,ll> solve(int idx,int par){
  if(adj[idx].size()==1 && adj[idx][0]==par){
    pair<ll,ll>p={1,1};
    return p;
  }
  ll white_col=1;
  ll black_col=1;
  for(ll i=0;i<(ll)adj[idx].size();i++){
    if(adj[idx][i]==par)continue;
    pair<ll,ll>p=solve(adj[idx][i],idx);
    white_col=((white_col %mod)*((p.first+p.second)%mod))%mod;
    black_col=((black_col%mod)*(p.first%mod))%mod;
  }
  pair<ll,ll>p={white_col,black_col};
  return p;
}
int main(){
  ll n;
  cin>>n;
  ll x,y;
  adj.resize(n+1);
  for(ll i=0;i<n-1;i++){
    cin>>x>>y;
    adj[x-1].push_back(y-1);
    adj[y-1].push_back(x-1);
  }
  ll idx=0;
  ll par=-1;
  pair<ll,ll>ans=solve(idx,par);
  ll val=((ans.first%mod)+(ans.second%mod))%mod;
  cout<<val<<endl;
}