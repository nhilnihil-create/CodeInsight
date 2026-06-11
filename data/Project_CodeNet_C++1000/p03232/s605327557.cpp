#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(i,n) for(int i=0;i<n;i++)

const ll MOD=1e9+7;
ll n,a[100010],h[100010]={};

ll ad(ll x,ll y){
  return (x+y)%MOD;
}

ll mlt(ll x,ll y){
  return (x*y)%MOD;
}

ll pwr(ll x,ll y){
  ll pw[32]={},w=1;
  pw[0]=x;
  fr(i,31) pw[i+1]=mlt(pw[i],pw[i]);
  fr(i,32){
    w=mlt(w,1+(y%2)*(pw[i]-1));
    y/=2;
  }
  return w;
}

ll inv(ll x){
  return pwr(x,MOD-2);
}

int main(){
  cin>>n;
  fr(i,n) cin>>a[i];
  fr(i,n) h[i+1]=ad(h[i],inv(i+1));
  ll ans=0;
  fr(i,n) ans=ad(ans,mlt(ad(h[i+1],h[n-i]-1),a[i]));
  fr(i,n) ans=mlt(ans,i+1);
  cout<<ans<<endl;
}