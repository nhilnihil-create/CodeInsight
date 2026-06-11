#include "bits/stdc++.h"
using namespace std;
#define int long long
//int mod=1e9+7;
int mod=998244353;

const int MAX = 510000;
const int MOD = 998244353;

int fac[MAX], finv[MAX], inv[MAX];

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
int comb(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

signed main(){
  COMinit();
  int n,a,b,k;
  cin>>n>>a>>b>>k;
  int ans=0;
  for(int i=0;i<=n;i++){
    int x=k-i*a;
    if(x%b==0)(ans+=comb(n,i)*comb(n,x/b))%=mod;
  }
  cout<<ans%mod<<endl;
}
