#include <bits/stdc++.h>
#define DUMP(x)  cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define IFOR(i, m, n) for(int i = n - 1; i >= m; i-- )
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define FOREACH(x,a) for(auto& (x) : (a) )
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
const int MOD = 1000000007;
/* テンプレートここまで */

/* 二項係数 C(n,k) mod p を計算 */
const int MAX = 100010;
long long fac[MAX], finv[MAX], inv[MAX];

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

int main() {
  int N;
  cin >> N;

  vector<int> A(N);
  ll sum = 0;

  REP(i, N){
    cin >> A[i];
  }

  COMinit();
  vector<ll> h(N+1);
  h[0] = 0;

  FOR(i, 1, N+1){
    h[i] = h[i-1] + inv[i] % MOD;
    h[i] %= MOD;
  }
 
  ll ans = 0;

  FOR(i, 1, N+1){
    ans += A[i-1] * (h[i] + h[N+1-i] % MOD - 1 % MOD) % MOD;
    ans %= MOD;
  }

  ans *= fac[N] %MOD;
  ans %= MOD;

  cout << ans << endl;
}