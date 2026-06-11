#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define itrfor(itr,A) for(auto itr = A.begin(); itr !=A.end();itr++)
typedef long long llong;
char moji[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char moji2[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char moji3[10]={'0','1','2','3','4','5','6','7','8','9'};
#define Sort(a) sort(a.begin(),a.end());
#define Reverse(a) reverse(a.begin(),a.end());
#define n_max int(1e5 + 5)
#define MOD int(1e9 + 7)


llong fac[n_max];  /// fac[n] = n!
llong finv[n_max]; /// (fac[n] * finv[n]) % MOD = 1
llong inv[n_max];  /// (n * inv[n]) % MOD = 1
 
void init() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  FOR (i, 2, n_max) {
    fac[i] = fac[i-1]*i % MOD;
    inv[i] = MOD - inv[MOD%i]*(MOD/i) % MOD;
    finv[i] = finv[i-1]*inv[i] % MOD;
  }
}
 
llong nCk (int n, int k) {
  if (n < k || k < 0 || n < 0) return 0;
  return fac[n]*finv[k]%MOD*finv[n-k]%MOD;
}

int main(){
    init();
    int n;
    cin >> n;
    llong A[n_max+5];
    REP(i,n) scanf("%lld",&A[i]);
    llong P[n_max+5];
    llong ruiseki[n_max+5];
    ruiseki[0]=0;
    REP(i,n){
        ruiseki[i+1] = ruiseki[i] + inv[i+1];
        ruiseki[i+1] %= MOD;
    }

    REP(i,n){
        P[i] = 0;
        P[i] += ruiseki[i+1];
        P[i] += ruiseki[n-i];
        P[i] = (P[i] + MOD -1)% MOD; 
    }

    llong ans=0;

    REP(i,n){
        ans += (P[i] * fac[n] % MOD) * A[i];
        ans%=MOD;
    }
    cout << ans << endl;
}