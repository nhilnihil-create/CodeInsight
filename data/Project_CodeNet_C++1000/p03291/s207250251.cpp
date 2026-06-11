#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i,s,n) for(ll i = (s); i < (n); i++)
#define rep0(i,n) rep(i,0,n)
#define rep1(i,n) rep(i,1,n+1)
#define repR(i,s,n) for(ll i = (n-1); i >= (s); i--)
#define repR0(i,n) repR(i,0,n)
#define repR1(i,n) repR(i,1,n+1)

#define BR "\n"
#define SP " "
#define SHOW(x) for(int i = 0; i < x.size(); i++) { cout << x[i] << SP; } cout << BR;
#define SHOW2(x) for(int j = 0; j < x.size(); j++) { SHOW(x[j]); } cout << BR;
#define fcout cout << fixed << setprecision(18)

ll MOD = 1e9 + 7;
ll powMod[100010];
void calc() {
  powMod[0] = 1;
  rep1(i, 100005) {
    powMod[i] = powMod[i - 1] * 3 % MOD;
  }
}

int main() {
  string S;
  cin >> S;

  S = "_" + S;
  int N = S.size();
  calc();

  vector<ll> A(N, 0), C(N, 0), Q(N, 0);
  rep(i, 1, N) {
    A[i] = A[i - 1];
    C[i] = C[i - 1];
    Q[i] = Q[i - 1];
    if (S[i] == 'A') A[i]++;
    if (S[i] == 'C') C[i]++;
    if (S[i] == '?') Q[i]++;
  }

  ll ans = 0;
  rep0(i, N - 1) {
    ll temp = 0, ac = 0;
    if (S[i] == 'B' || S[i] == '?') {
      ll la = A[i - 1];
      ll lq = Q[i - 1];
      ll rc = C[N - 1] - C[i];
      ll rq = Q[N - 1] - Q[i];

      ac = la * rc % MOD;
      if (ac != 0) temp = (temp + ac * powMod[lq + rq]) % MOD;

      ac = lq * rc % MOD;
      if (ac != 0) temp = (temp + ac * powMod[lq - 1 + rq]) % MOD;

      ac = la * rq % MOD;
      if (ac != 0) temp = (temp + ac * powMod[lq + rq - 1]) % MOD;

      ac = lq * rq % MOD;
      if (ac != 0) temp = (temp + ac * powMod[lq - 1 + rq - 1]) % MOD;
    }
    ans = (ans + temp) % MOD;
  }

  cout << ans << BR;
  return 0;
}