#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(i,n) for(int i=0;i<n;i++)
const ll MOD=998244353;
ll n,a,b,k;

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

ll nC[300010]={1};
ll comb(ll r){
  if(nC[r]==0) nC[r]=mlt(comb(r-1),mlt(n-r+1,inv(r)));
  return nC[r];
}

int main(){
  cin>>n>>a>>b>>k;
  ll ans=0,j,l,p;
  fr(i,n+1){
    j=i*a;l=k-j;p=l/b;
    if(l<0) break;
    if(p>n || l%b>0) continue;
    ans=ad(ans,mlt(comb(i),comb(p)));
  }
  cout<<ans<<endl;
}