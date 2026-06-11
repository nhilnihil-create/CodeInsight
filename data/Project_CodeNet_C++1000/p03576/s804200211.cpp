#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll N; cin >> N;
  ll K; cin >> K;
  vector<pair<ll, ll>> P(N);
  for (ll i = 0; i < N; i++) {
    ll x, y;
    cin >> x >> y;
    P[i] = make_pair(x, y);
  }

  ll ans = -1;
  for (ll l = 0; l < N; l++) {
    for (ll r = 0; r < N; r++) {
      for (ll u = 0; u < N; u++) {
        for (ll d = 0; d < N; d++) {
          pair<ll, ll> pl = P[l], pr = P[r], pu = P[u], pd = P[d];
          ll cnt = 0;
          for (ll i = 0; i < N; i++) {
            if (P[i].first >= pl.first && P[i].first <= pr.first
                && P[i].second >= pd.second && P[i].second <= pu.second) {
                  cnt++;
                }
          }
          if (cnt >= K) {
            ll temp = (P[r].first - P[l].first) * (P[u].second - P[d].second);
            if (temp == 0) continue;
            else if (ans == -1) ans = temp;
            else ans = min(ans, temp);
          }
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}