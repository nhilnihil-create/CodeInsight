#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
constexpr int MOD = 998244353;
constexpr int INF = 2147483647;
void yes(bool expr) {
  cout << (expr ? "Yes" : "No") << "\n";
}
lint power(lint x, lint n, lint mod) {
  lint ret = 1;
  while(n > 0) {
    if(n & 1) (ret *= x) %= mod;
    (x *= x) %= mod;
    n >>= 1;
  }
  return ret;
}
lint ncr(lint n, lint r, lint mod, vector<lint> &fact, vector<lint> &finv) {
  if(n < 0 || r < 0 || n-r < 0) return 0;
  return fact[n]*finv[r]%mod*finv[n-r]%mod;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  lint N, A, B, K;
  cin >> N >> A >> B >> K;
  vector<lint> fact(N+1);
  fact[0] = 1;
  FOR(i, 1, N+1) fact[i] = fact[i-1] * i % MOD;
  vector<lint> finv(N+1);
  finv[N] = power(fact[N], MOD-2, MOD);
  IFOR(i, 0, N) finv[i] = finv[i+1] * (i+1) % MOD;
  lint ans = 0;
  REP(i, N+1) {
    lint p = i;
    if(K-p*A < 0 || (K-p*A)%B != 0) continue;
    lint q = (K-p*A) / B;
    if(q < 0 || q > N) continue;
    ans = (ans + ncr(N, p, MOD, fact, finv) * ncr(N, q, MOD, fact, finv) % MOD) % MOD;
  }
  cout << ans << endl;
}