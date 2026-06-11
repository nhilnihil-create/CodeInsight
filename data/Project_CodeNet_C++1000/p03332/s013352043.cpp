#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;
const int MAX = 4e5;
const ll mod = 998244353;

ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i-1] * (ll)i % mod;
        inv[i] = mod - inv[mod%i] * (mod/(ll)i) % mod;
        finv[i] = finv[i-1] * inv[i] % mod;
    }
}

ll COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n-k] % mod) % mod;
}


int main(){
  ll n, a, b, k;
  cin >> n >> a >> b >> k;
  COMinit(); 
  ll ans = 0;
  for(ll c = 0; c <= n; c++) {
    if(c*a <= k && (k-a*c) % b == 0 && (k-a*c)/b <= n) {
      ll d = (k-a*c)/b;
      (ans += COM(n,c)*COM(n,d)) %= mod; 
    }
  }
  cout << ans << endl;
  return 0;
}