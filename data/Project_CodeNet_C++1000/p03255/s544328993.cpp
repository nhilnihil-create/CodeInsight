#include <bits/stdc++.h>
#define REP(i, a, n) for (ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

int main(void) {
  ll N, X;
  cin >> N >> X;
  vector<ll> x(N);
  REP(i, 0, N) cin >> x[i];
  reverse(x.begin(), x.end());

  vector<ll> sum(N + 1);
  REP(i, 0, N) sum[i + 1] = sum[i] + x[i];

  ll ans = 1LL << 60;
  REP(k, 1, N + 1) {
    ll cost = k * X + N * X;
    for (ll i = 0; i * k < N; i++) {
      ll t = i + 1;
      ll l = k * i, r = min(l + k, N);
      if (t == 1) {
        cost += (sum[r] - sum[l]) * 5;
      } else {
        cost += (sum[r] - sum[l]) * (2 * t + 1);
      }
      if (cost > ans) break;
    }
    ans = min(ans, cost);
  }
  cout << ans << endl;
}