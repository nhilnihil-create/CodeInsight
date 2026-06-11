#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); (i)++)
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); (i)--)
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
using namespace std;
typedef long long lint;

const long mod = 1e9 + 7;

long powmod(long x, long n){
  long ret = 1;
  while(n > 0){
    if(n&1) ret *= x, ret %= mod, n -= 1;
    else x *= x, x %= mod, n >>= 1;
  }
  return ret;
}

vector<long> fact;
vector<long> revfact;

void setfact(int n){
  fact.resize(n+1); revfact.resize(n+1);
  fact[0] = 1;
  rep(i, n) fact[i+1] = fact[i] * (i+1) % mod;
  
  revfact[n] = powmod(fact[n], mod-2);
  for(int i=n-1; i>=0; i--) revfact[i] = revfact[i+1] * (i+1) % mod;
}

int main(){
    int n; cin >> n;
    int A[100010]; rep(i, n) cin >> A[i];
    setfact(n);
    long p[100010];
    rep(i, n+1) p[i] = (fact[n] * (powmod(i, mod-2))) % mod;
    long psum[100010];
    rep(i, 100010) psum[i] = 0;
    rep(i, n+1) psum[i+1] = (psum[i] + p[i]) % mod;
    long a[n]; rep(i, n) a[i] = 0;
    rep(i, n) a[i] = (psum[n-i+1] + psum[i+2] - psum[2] + mod) % mod;
    long ans = 0;
    rep(i, n) ans = (ans + a[i] * A[i] % mod) % mod;
    cout << ans << endl;
    /*rep(i, n) cout << a[i] << " ";
    cout << endl;
    rep(i, n+2) cout << psum[i] << " ";*/
}