#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

#define MAX_N 200020
ll inv[MAX_N+10],fac[MAX_N+10],ifac[MAX_N+10];

void setComb(){
  inv[0]=1;inv[1]=1;fac[1]=1;ifac[1]=1;fac[0]=1;ifac[0]=1;
  for(int i=2;i<MAX_N;i++){
    inv[i]=(-MOD/i)*inv[MOD%i]%MOD;
    fac[i]=fac[i-1]*i%MOD;
    ifac[i]=ifac[i-1]*inv[i]%MOD;

    inv[i]=(inv[i]+MOD)%MOD;
    fac[i]=(fac[i]+MOD)%MOD;
    ifac[i]=(ifac[i]+MOD)%MOD;
  }
  return;
}

ll comb(ll n,ll k){
  if(n<k||n<0||k<0) return 0;
  else return ((fac[n]*ifac[k]%MOD*ifac[n-k]%MOD+MOD)%MOD);
}

ll hcomb(ll n,ll r){
  if(n==0&&r==0) return 1;
  else if(n<0||r<0) return 0;
  else return comb(n+r-1,r-1);
}

int main(){
  ll N;
  cin>>N;
  vector<ll> A(N);
  rep(i,N) cin>>A[i];

  setComb();

  vector<ll> sum(N+1,0);
  for(int i=1;i<=N;i++) sum[i]=(sum[i-1]+inv[i])%MOD;

  ll ans=0;
  for(int i=0;i<N;i++){
    ll c=(sum[i+1]+sum[N-i]-inv[1]+MOD)%MOD;
    ll res=A[i]*c%MOD;
    ans=(ans+res)%MOD;
  }
  ans=ans*fac[N]%MOD;

  cout<<ans<<endl;

  return 0;
}
