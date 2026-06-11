#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;

ll INF = (1ll << 40);

int main() {
  ll N;
  cin >> N;

  vi A(N);
  for (ll i = 0; i < N; i++) {
    cin >> A[i];
    A[i] *= 2;
  }

  vi v1(N + 1);
  for (ll i = 0; i < N; i++) {
    v1[i + 1] = v1[i] + A[i];
  }

  vi v2(N + 1);
  for (ll i = 0; i < N; i++) {
    v2[i + 1] = v2[i] + A[N - 1 - i];
  }

  ll ans = INF;

  for (ll j = 2; (N - j) >= 2; j++) {
    // 左半分の個数がj
    // 左半分の和はv1[j]

    ll l_min = INF, l_max = 0;
    ll r_min = INF, r_max = 0;

    {
      ll k = distance(v1.begin(), lower_bound(v1.begin(), v1.end(), v1[j] / 2));

      ll tmp = INF;
      for (ll l = k - 1; l <= k + 1; l++) {
        if (l >= 1 && l < j) {
          if (abs(v1[j] - v1[l] * 2) < tmp) {
            l_min = min(v1[j] - v1[l], v1[l]);
            l_max = max(v1[j] - v1[l], v1[l]);
            tmp = abs(v1[j] - v1[l] * 2);
          }
        }
      }
    }

    {
      // 右半分の個数がN-j
      ll k = distance(v2.begin(), lower_bound(v2.begin(), v2.end(), v2[N - j] / 2));

      ll tmp = INF;
      for (ll l = k - 1; l <= k + 1; l++) {
        if (l >= 1 && l < N - j) {
          if (abs(v2[N - j] - v2[l] * 2) < tmp) {
            r_min = min(v2[N - j] - v2[l], v2[l]);
            r_max = max(v2[N - j] - v2[l], v2[l]);
            tmp = abs(v2[N - j] - v2[l] * 2);
          }
        }
      }
    }

    ans = min(ans, max(r_max, l_max) - min(l_min, r_min));
  }

  cout << ans / 2 << endl;
}