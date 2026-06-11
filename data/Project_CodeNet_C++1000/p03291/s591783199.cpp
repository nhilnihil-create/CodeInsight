#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using P = pair<lint, lint>;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
constexpr int MOD = 1000000007;
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
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string S;
  cin >> S;
  lint N = S.size();
  vector<lint> SA(N+1);
  REP(i, N) SA[i+1] = SA[i] + (S[i]=='A' ? 1 : 0);
  vector<lint> SC(N+1);
  REP(i, N) SC[i+1] = SC[i] + (S[i]=='C' ? 1 : 0);
  vector<lint> SQ(N+1);
  REP(i, N) SQ[i+1] = SQ[i] + (S[i]=='?' ? 1 : 0);
  lint Q = 0;
  REP(i, N) if(S[i] == '?') Q++;
  lint ans = 0;
  FOR(i, 1, N-1) {
    if(S[i] == 'B') {
      ans = (ans + SA[i] * (SC[N]-SC[i+1]) % MOD * power(3, Q, MOD) % MOD) % MOD;
      ans = (ans + SQ[i] * (SC[N]-SC[i+1]) % MOD * power(3, Q-1, MOD) % MOD) % MOD;
      ans = (ans + SA[i] * (SQ[N]-SQ[i+1]) % MOD * power(3, Q-1, MOD) % MOD) % MOD;
      ans = (ans + SQ[i] * (SQ[N]-SQ[i+1]) % MOD * power(3, Q-2, MOD) % MOD) % MOD;
    } else if(S[i] == '?') {
      ans = (ans + SA[i] * (SC[N]-SC[i+1]) % MOD * power(3, Q-1, MOD) % MOD) % MOD;
      ans = (ans + SQ[i] * (SC[N]-SC[i+1]) % MOD * power(3, Q-2, MOD) % MOD) % MOD;
      ans = (ans + SA[i] * (SQ[N]-SQ[i+1]) % MOD * power(3, Q-2, MOD) % MOD) % MOD;
      ans = (ans + SQ[i] * (SQ[N]-SQ[i+1]) % MOD * power(3, Q-3, MOD) % MOD) % MOD;
    }
  }
  cout << ans << endl;
}