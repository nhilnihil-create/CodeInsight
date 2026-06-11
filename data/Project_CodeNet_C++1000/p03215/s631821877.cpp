#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll N; cin >> N;
  ll K; cin >> K;
  vector<ll> A(N); for (ll i = 0; i < N; i++) cin >> A[i];

  ll M = (N + 1) * N / 2;
  vector<ll> S(M);

  ll index = 0;
  for (ll i = 0; i < N; i++) {
    ll s = 0;
    for (ll j = i; j < N; j++) {
      s += A[j];
      S[index] = s;
      index++;
    }
  }

  ll ans = 0;
  for (ll i = 40; i >= 0; i--) {
    ll d = (1ll<<i);
    ll cnt = 0;
    for (ll j = 0; j < M; j++) {
      if (((ans + d) & S[j]) == ans + d) cnt++;
    }
    if (cnt >= K) ans += d;
  }
  cout << ans << '\n';
  return 0;
}