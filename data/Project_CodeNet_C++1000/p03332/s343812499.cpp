#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MAX 300003
#define MOD 998244353

long long modpow(long long a,long long n,long long mod){
  long long res=1;
  while(n>0){
    if(n&1){       //nのbitと...00001を比較  nが2で割り切れるならtrue
      res=(res*a)%mod;
    }
    a=(a*a)%mod;
    n>>=1;
  }
  return res;
}

long long modinv(long long a,long long mod){
  return modpow(a,mod-2,mod);
}

long long fac[MAX],finv[MAX],inv[MAX];

void COMinit(){
  fac[0]=fac[1]=1;
  finv[0]=finv[1]=1;
  inv[1]=1;
  for(int i=2;i<MAX;i++){
    fac[i]=(fac[i-1]*i)%MOD;
    inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
    finv[i]=finv[i-1]*inv[i]%MOD;
  }
}

long long COM(int n,int k){
  if(n<k){
    return 0;
  }
  if(n<0||k<0){
    return 0;
  }
  return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}

int main(){
  ll N,A,B,K;
  cin>>N>>A>>B>>K;

  COMinit();

  ll ans=0;
  for(ll i=0;i<=N;i++){
    if(A*i>K){
      break;
    }
    if((K-A*i)%B!=0){
      continue;
    }
    ll j=(K-A*i)/B;
    ans+=COM(N,i)*COM(N,j)%MOD;
    ans%=MOD;
  }
  cout<<ans<<endl;
}
