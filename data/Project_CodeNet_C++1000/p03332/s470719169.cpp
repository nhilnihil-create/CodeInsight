#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAX=510000;
const int MOD=998244353;
long long fac[MAX],finv[MAX],inv[MAX];

void COMinit(){
  fac[0]=fac[1]=1;
  finv[0]=finv[1]=1;
  inv[1]=1;
  for(int i=2;i<MAX;i++){
    fac[i]=fac[i-1]*i%MOD;
    inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
    finv[i]=finv[i-1]*inv[i]%MOD;
  }
}

long long COM(int n,int k){
  if(n<k) return 0;
  if(n<0||k<0) return 0;
  return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}

int main(){
  COMinit();
  ll mod=998244353;
  ll n,a,b,k;
  ll ans=0;
  cin>>n>>a>>b>>k;
  for(ll i=0;i<=n;i++){
    ll x=k-a*i;
    if(x%b==0&&x/b>=0&&x/b<=n){
      ll j=x/b;
      ans+=(COM(n,i)*COM(n,j))%mod;
      ans%=mod;
    }
  }
  cout<<ans<<endl;
}