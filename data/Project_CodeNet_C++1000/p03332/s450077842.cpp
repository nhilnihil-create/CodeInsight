#include "bits/stdc++.h"
using namespace std;
typedef int64_t ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define SIZE(a) int((a).size())
const int MAX = 300010;
const int MOD = 998244353;

ll fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
int main(){
  ll n,a,b,k,n_copy,ans=0;
  cin>>n>>a>>b>>k;
  COMinit();
  FOR(i,1,n+1){
    if((k-a*i)%b==0){
      int j=(k-a*i)/b;
      if(0<=j&&j<=n){ans=(ans+COM(n,i)*COM(n,j))%MOD;}
    }
  }
  
  if(ans!=0){cout<<ans<<endl;}
  else{cout<<1<<endl;}
  
}  

