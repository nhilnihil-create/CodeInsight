#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main(){
  int n;cin>>n;
  vector<ll> a(n);
  rep(i,n)cin>>a[i];
  vector<ll> sum(n+1);
  rep(i,n)sum[i+1]=sum[i]+a[i];
  map<ll,ll> mp;
  rep(i,n+1)mp[sum[i]]++;
  ll ans=0;
  for(auto x:mp){
    ans+=x.second*(x.second-1)/2;
  }
  cout<<ans<<endl;
}