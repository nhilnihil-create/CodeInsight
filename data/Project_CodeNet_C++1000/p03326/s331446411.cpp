#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  ll N, M;
  cin >> N >> M;
  vector<tuple<ll, ll, ll>> xyz(N);
  for (ll i = 0; i < N; ++i) {
    ll x, y, z;
    cin >> x >> y >> z;
    xyz.at(i) = make_tuple(x, y, z);
  }
  ll ans = 0;
  for (ll x_plus = 0; x_plus <= 1; ++x_plus) {
    for (ll y_plus = 0; y_plus <= 1; ++y_plus) {
      for (ll z_plus = 0; z_plus <= 1; ++z_plus) {
        vector<ll> point(N);
        for (ll i = 0; i < N; ++i) {
          ll temp = 0;
          if (x_plus == 1) {
            temp += get<0>(xyz.at(i));
          }
          else {
            temp -= get<0>(xyz.at(i));
          }
          if (y_plus == 1) {
            temp += get<1>(xyz.at(i));
          }
          else {
            temp -= get<1>(xyz.at(i));
          }
          if (z_plus == 1) {
            temp += get<2>(xyz.at(i));
          }
          else {
            temp -= get<2>(xyz.at(i));
          }
          point.at(i) = temp;
        }
        ll ans_temp = 0;
        sort(point.begin(), point.end());
        reverse(point.begin(), point.end());
        for (ll i = 0; i < M; ++i) {
          ans_temp += point.at(i);
        }
        ans = max(ans, ans_temp);
      }
    }
  }
  cout << ans << endl;
}
