#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ll;

map<ll, ll> f(ll n) {
  map<ll, ll> res;
  for (ll i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      ++res[i];
      n /= i;
    }
  }
  if (n != 1) res[n] = 1;
  return res;
}

int main() {
  ll N, P;
  cin >> N >> P;
  if (N == 1) {
    cout << P << endl;
    return 0;
  }
  if (P == 1) {
    cout << 1 << endl;
    return 0;
  }
  map<ll, ll> M = f(P);
  ll ans = 1;
  for (auto p : M) {
    ll x = p.first, n = p.second;
    ll tmp = n / N;
    for (ll j = 0; j < tmp; j++) {
      ans *= x;
    }
  }
  cout << ans << endl;
}