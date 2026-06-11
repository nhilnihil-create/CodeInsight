#include<bits/stdc++.h>

using namespace std;
const long long MOD=998244353;

long long fac[300001],finv[300001],inv[300001];

void table() {
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<300001;i++){
        fac[i]= fac[i-1]*i%MOD;
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
}

long long comb(int n, int k){
    if(n<k) return 0;
    if(n<0 || k<0) return 0;
    return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}

int main(){
  table();
  long long N,A,B,K,ans=0; cin>>N>>A>>B>>K;
  for(long long a=0;a<=N;a++){
    if(a*A>K) break;
  	if((K-a*A)%B==0 && (K-a*A)/B<=N){
      long long b=(K-a*A)/B;
    	ans+=(comb(N,a)*comb(N,b))%MOD;
      ans%=MOD;
    }
  }
 printf("%lld",ans); 
}
