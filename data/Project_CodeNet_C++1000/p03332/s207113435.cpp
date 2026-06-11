#include<bits/stdc++.h>
using ll=long long;
using namespace std;
const int MAX=510000;
const int MOD=998244353;
ll fan[MAX],inv[MAX],finv[MAX];
void COMinit(){
  fan[0]=fan[1]=1;
  finv[0]=finv[1]=1;
  inv[1]=1;
  for(ll i=2;i<MAX;i++){
    fan[i]=fan[i-1]*i%MOD;
    inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
    finv[i]=finv[i-1]*inv[i]%MOD;
  }
}
ll COM(ll a,ll k){
  if(a<0||k<0)return 0;
  if(a<k)return 0;
  return fan[a]*(finv[a-k]*finv[k]%MOD)%MOD;
}
int main(){
ll N,A,B,K;
cin>>N>>A>>B>>K;
COMinit();
ll ans=0;
for(ll i=0;i<=N;i++){
  ll j=(K-i*A)/B;
  if(i*A+j*B!=K)continue;
  ans+=(COM(N,i)*COM(N,j))%MOD;
  ans%=MOD;
}
  while(ans<0){
    ans+=MOD;
  }
  cout<<ans%MOD<<endl;
}