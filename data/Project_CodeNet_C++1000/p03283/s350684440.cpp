#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll sum[505][505];
ll N,M,Q;
int main(){
  cin>>N>>M>>Q;
  for(ll i=0;i<M;i++){
  ll l,r;cin>>l>>r;
    sum[l][r]++;
  }for(ll i=0;i<=N;i++)
    for(ll j=1;j<=N;j++)
      sum[i][j]+=sum[i][j-1];
  for(ll j=0;j<=N;j++)
    for(ll i=1;i<=N;i++)
      sum[i][j]+=sum[i-1][j];
  for(ll i=0;i<Q;i++){
  ll p,q;cin>>p>>q;
    ll ans=sum[N][q]-sum[p-1][q];
    cout<<ans<<endl;
  }
    
  return 0;
}