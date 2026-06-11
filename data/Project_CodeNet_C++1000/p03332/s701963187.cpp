#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 998244353;
ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
ll fact[400003];
ll ifact[400003];
ll Combination(ll a,ll b) {
  ll s = (fact[a] * ifact[b]) % Mod;
  return (s * ifact[a-b]) % Mod;
}
int main() {
  fact[0] = 1;
  ifact[0] = 1;
  for (int i = 1; i <= 400002; i++) {
    fact[i] = fact[i-1] * i;
    fact[i] %= Mod;
    ifact[i] = modinv(fact[i],Mod);
  }
  ll N,A,B,K;
  cin >> N >> A >> B >> K;
  ll ans = 0;
  for (ll i = 0; i <= N; i++) {
    if ((K - (A * i)) % B == 0) {
      ll a = i;
      ll b = (K - (A * i)) / B;
      if (0 <= b && b <= N) {
        ll res = Combination(N,a);
        res %= Mod;
        res *= Combination(N,b);
        res %= Mod;
        ans += res;
        ans %= Mod;
      }
    }
  }
  cout << ans << endl;
  return 0;
}