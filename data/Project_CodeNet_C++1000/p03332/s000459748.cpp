#include <iostream>
using namespace std;

typedef long long ll;

ll mod=998244353;

ll modinv(ll a){
  ll b=mod,u=1,v=0;
  while(b){
    ll t=a/b;
    a-=t*b; swap(a,b);
    u-=t*v; swap(u,v);
  }
  u%=mod;
  if(u<0) u+=mod;
  return u;
}

ll fac[300010];

void modfac(){
  fac[0]=1;
  for(ll i=1;i<300010;i++){
    fac[i]=(fac[i-1]*i)%mod;
  }
}

ll modcomb(ll n,ll k){
  return ((fac[n]*modinv(fac[k]))%mod*modinv(fac[n-k]))%mod;
}

int main(){
  ll n,a,b,k;
  cin >> n >> a >> b >> k;
  modfac();
  ll ans=0;
  for(ll i=0;i<=n;i++){
    ll x=k-a*i;
    if(x>=0&&x%b==0&&x/b<=n){
      ll count=(modcomb(n,i)*modcomb(n,x/b))%mod;
      ans=(ans+count)%mod;
    }
  }
  cout << ans << endl;
}
