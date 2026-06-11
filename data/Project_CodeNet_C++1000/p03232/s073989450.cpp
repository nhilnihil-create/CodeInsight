#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const ll MOD = 1000000007;
ll N;
ll A[100010];
ll c[100010];
ll fac;

ll modPow(ll x, ll n) {
  if (n == 0) return 1;
  ll res = 1;
  while (n) {
    if (n & 1) (res *= x) %= MOD;
    (x *= x) %= MOD;
    n >>= 1;
  }
  return res;
}

ll modInv(ll x) {
  return modPow(x, MOD-2);
}

void make() {
  c[1] = 1;
  for (int i = 2; i < 100010; i++) {
    c[i] = (c[i-1] + modInv(i)) % MOD;
  }
  fac = 1;
  for (int i = 1; i <= N; i++) {
    (fac *= i) %= MOD;
  }
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  make();
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    ll sum = c[i+1] + c[N-i];
    (sum += MOD-1) %= MOD;
    (ans += sum*A[i]) %= MOD;
  }
  (ans *= fac) %= MOD;
  cout << ans << endl;

  return 0;
}