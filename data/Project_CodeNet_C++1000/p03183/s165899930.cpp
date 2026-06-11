#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ln '\n';
int lim=1e4+2;
int inf=1e9+7;
int n;vector<int> w,s;
vector<ll> val;
vector<vector<ll> > dp;vector<pair<int,int> > v;
ll solve(int i,int si){
  if(i==n){
    return 0;
  }
  if(dp[i][si]!=-1){
    return dp[i][si];
  }else{
    int ind=(v[i].second);
    int wi=w[ind];
    ll tmp1=0;
    if(wi<=si){
      tmp1=val[ind]+solve(i+1,min(si-wi,s[ind]));
    }
    ll tmp2=solve(i+1,si);
    dp[i][si]=max(tmp1,tmp2);
    return dp[i][si];
  }
}
int main()
{ 
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n;
  w.resize(n);s.resize(n);val.resize(n);dp.resize(n+1,vector<ll>(2*lim+1,-1));
  for(int i=0;i<n;i++){
    cin>>w[i]>>s[i]>>val[i];
    v.push_back(make_pair(w[i]+s[i],i));
  }
  sort(v.rbegin(),v.rend());
  cout<<solve(0,2*lim)<<ln;
}