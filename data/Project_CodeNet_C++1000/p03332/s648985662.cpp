// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
#define MOD 998244353
#define MAX 510000

ll fac[MAX], finv[MAX], inv[MAX];

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

long long COM(int n, int k){
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

signed main(){
  ll n,a,b,k,ans=0,res;
  COMinit();
  cin >> n >> a >> b >> k;
  for(ll i=0;i<=n;i++){
    res = k-a*i;
    if(res<0) break;
    if(res%b == 0){
      ans += (COM(n,i)*COM(n,res/b))%MOD;
      ans %= MOD;
    }
  }
  cout << ans << endl;
}
