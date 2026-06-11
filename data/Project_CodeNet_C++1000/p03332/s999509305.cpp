#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef pair<int, int> pii;
typedef complex<double> xy_t;

const lint mod = 998244353;

lint powmod(long x, long n){
  lint ret = 1;
  while(n > 0){
    if(n&1) ret *= x, ret %= mod, n -= 1;
    else x *= x, x %= mod, n >>= 1;
  }
  return ret;
}

vector<lint> fact;
vector<lint> revfact;

void setfact(int n){
  fact.resize(n+1); revfact.resize(n+1);
  fact[0] = 1;
  rep(i, n) fact[i+1] = fact[i] * (i+1) % mod;
  
  revfact[n] = powmod(fact[n], mod-2);
  for(int i=n-1; i>=0; i--) revfact[i] = revfact[i+1] * (i+1) % mod;
}

lint getC(int n, int r){
  return fact[n] * revfact[r] % mod * revfact[n-r] % mod;
}

int main(){
    int n;
    lint a, b, K;
    scanf("%d%lld%lld%lld", &n, &a, &b, &K);
    
    setfact(n);
    lint ans = 0;
    rep(p, n+1)if((K-a*p) % b == 0){
        lint q = (K-a*p) / b;
        if(0<=q && q<=n) (ans += getC(n, p) * getC(n, q) % mod) %= mod;
    }
    
    printf("%lld\n", ans);
}