#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  ll mod = 1000000007;
  ll N;
  cin >> N;
  vector<ll> C(N);
  vector<vector<ll>> color(2 * 100000);
  for (ll i = 0; i < N; ++i) {
    ll c;
    cin >> c;
    C.at(i) = c - 1;
    color.at(c - 1).push_back(i);
  }
  vector<ll> dp(N + 1, 0);
  dp.at(0) = 1;
  for (ll i = 0; i < N; ++i) {
    dp.at(i + 1) = dp.at(i);
    ll index = lower_bound(color.at(C.at(i)).begin(), color.at(C.at(i)).end(), i) - color.at(C.at(i)).begin() - 1;
    if (index >= 0) {
      ll j = color.at(C.at(i)).at(index);
      if (i - j > 1) {
        // cout << i << ' ' << j << endl;
        dp.at(i + 1) = (dp.at(i + 1) + dp.at(j + 1)) % mod;
      }
    }
  }
  cout << dp.at(N) << endl;
  // for (ll i = 0; i < N + 1; ++i) {
  //   cout << dp.at(i) << ' ';
  // }
  // cout << endl;
}
