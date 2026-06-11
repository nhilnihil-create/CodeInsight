#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll=long long;
int main(){
  ll n,m;cin>>n>>m;
  if(n==1||m==1){
    if(n==1&&m==1)return cout<<1,0;
    ll x=max(n,m);
    cout<<max(ll(0),x-2);
  }else cout<<max((n*m)-2*(n+m)+4,ll(0));
}