#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll N, K; cin >> N >> K;
  vector<ll> V(N); for (ll i = 0; i < N; i++) cin >> V[i];
  vector<ll> S(N + 1, 0);
  for (ll i = 0; i < N; i++) {
    S[i + 1] = S[i] + V[i];
  }

  ll ans = 0;
  for (ll l = 0; l < N + 1; l++) {
    for (ll r = l; r < N + 1; r++) {
      if (N - (r - l) > K) continue;
      ll t = K - (N - (r - l));
      ll s = 0;

      vector<ll> A(N, 1);
      for (ll i = 0; i < N; i++) {
        if (!(l <= i && i < r)) {
          s += V[i];
          A[i] = V[i];
        }
        sort(A.begin(), A.end());
      }
      for (ll i = 0; i < t; i++) {
        if (A[i] >= 0) break;
        s -= A[i];
      }
      // cout << l << ' ' << r << ' ' << s << '\n';
      ans = max(ans, s);
    }
  }
  cout << ans << '\n';
  return 0;
}