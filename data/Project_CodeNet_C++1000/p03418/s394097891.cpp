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

int main() {
  ll N, K;
  cin >> N >> K;

  ll ans = 0;
  rep(b, K + 1, N + 1) {
    ll q = N / b;
    ll r = N - q * b;
    ans += q * (b - K) + max(r - (K - 1), 0LL);
  }
  if (K == 0) ans = N * N;

  cout << ans << BR;
  return 0;
}