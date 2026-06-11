#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

ll MOD = 1000000007;

ll inverse(ll i) {
  ll x = MOD - 2;
  ll tmp = i;
  ll ret = 1;
  while (x) {
    if (x % 2 == 1) {
      ret = (ret * tmp) % MOD;
    }
    x /= 2;
    tmp = (tmp * tmp) % MOD;
  }
  return ret;
}

int main() {
  ll N;
  cin >> N;

  vector<ll> A(N);
  for (ll i = 0; i < N; i++) {
    cin >> A[i];
  }

  unordered_map<ll, ll> m1;
  for (ll i = 1; i <= N; i++) {
    m1[i] = inverse(i);
  }

  unordered_map<ll, ll> m2;
  {
    ll sum = 0;
    for (ll i = 1; i <= N; i++) {
      sum += m1[i];
      sum %= MOD;
      m2[i] = sum;
    }
  }

  ll i1 = 1;
  for (ll i = 1; i <= N; i++) {
    i1 = (i1 * i) % MOD;
  }

  ll ans = 0;
  for (ll i = 0; i < N; i++) {
    ans += (i1 * A[i] % MOD) * (m2[abs(-i) + 1] + m2[abs(N - 1 - i) + 1] - 1);
    ans %= MOD;
  }

  cout << ans << endl;
}