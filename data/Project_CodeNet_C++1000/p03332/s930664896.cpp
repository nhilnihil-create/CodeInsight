#include<bits/stdc++.h>
using namespace std;
static const int64_t mod=998244353;
int64_t f(int64_t x,int64_t y){
if(y==0)
  return 1;
  else if(y%2==0)
    return (f(x,y/2)*f(x,y/2))%mod;
  else
    return (x*((f(x,y/2)*f(x,y/2))%mod))%mod;
}
int main(){
  int64_t N,A,B,K;
  cin>>N>>A>>B>>K;
  vector<int64_t>Comb(N+1);
  Comb[0]=1;
  for(int64_t i=1;i<=N;i++)
    Comb[i]=((N+1-i)*((Comb[i-1]*f(i,mod-2))%mod))%mod;
  int64_t ans=0;
  for(int64_t i=0;i<=N;i++){
  if(K%B==(i*A)%B){
  int64_t c=(K-i*A)/B;
    if(0<=c && c<=N)
      ans=(ans+Comb[i]*Comb[c])%mod;
  }
   }cout<<ans<<endl;
  return 0;
}