#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long
const int MOD = 998244353;

struct Combination{
  const int MOD = 998244353;

  vector<int> fact; //　fact[i] = iの階乗
  void init(int n){
    fact.resize(n+1);
    fact[0] = fact[1] = 1;
    for(int i = 2; i <= n; i++){
      fact[i] = i * fact[i-1] % MOD;
    }
  }

  int nCr(int n,int r){ // nCr = n!/r!(n-r)!
    return fact[n] * mod_pow(fact[r]*fact[n-r]%MOD,MOD-2,MOD) % MOD;
  }

  int mod_pow(int n,int p,int MOD){ // a/n ≡ a*n^(p-2) nとpは互いに素
    int r = 1;
    for(; p > 0; p >>= 1){
      if(p & 1LL) r = (r * n) % MOD;
      n = (n * n) % MOD;
    }
    return r; // r = n^p % MOD
  }

}comb;

signed main(){

  int n, a, b, k; cin >> n >> a >> b >> k;
  int ans = 0;
  comb.init(n);
  for(int i = 0; i <= n; i++){
    int right = k - a * i;
    if(right % b != 0 || right/b < 0 || right/b > n) continue;
    ans += comb.nCr(n, i) * comb.nCr(n, right / b);
    ans %= MOD;
  }
  cout << ans << endl;

  return 0;
}
