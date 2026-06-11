#include <bits/stdc++.h>
#define FOR(v, a, b) for(int v = (a); v < (b); ++v)
#define FORE(v, a, b) for(int v = (a); v <= (b); ++v)
#define REP(v, n) FOR(v, 0, n)
#define REPE(v, n) FORE(v, 0, n)
#define REV(v, a, b) for(int v = (a); v >= (b); --v)
#define RS resize
#define CLR clear
#define PB push_back
#define ALL(x) (x).begin(), (x).end()
#define LLI long long int
using namespace std;

int powerMod(int n, int p, int m){
  if(p==0) return 1;
  if(p==1) return n;

  int x = 1;
  int k = powerMod(n, p/2, m);
  x = (1LL*x*k*k)%m;
  if(p%2) x = (1LL*x*n)%m;
  return x;
}

int modInverse(int n, int m){
  return powerMod(n,m-2,m);
}

int factorialMod(int n, int m){
  int k = 1;
  for(int i = 1; i <= n; ++i){
    k = (1LL*k*i) % m;
  }
  return k;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int mod = 1000000007;
  int n;
  cin >> n;

  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<LLI> inv(n);
  
  FOR(i,0,n) inv[i] = modInverse(i+1,mod);
  FOR(i,1,n) inv[i] = (1LL*inv[i-1]+inv[i])%mod;

  //REP(i,n) cout << inv[i] << endl;

  LLI ans=0;

  REP(i,n){
    (ans += (inv[i] + inv[n-i-1] - 1) * a[i]) %= mod;
  }

  int f = factorialMod(n, mod);
  ans = (ans*f) % mod;

  cout << ans << endl;
  
  return 0;
}
