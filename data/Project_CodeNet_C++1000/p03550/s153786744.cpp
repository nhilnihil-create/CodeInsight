#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  ll N, Z, W;
  cin >> N >> Z >> W;
  ll ans = 0;
  ll a_n1;
  for (ll i = 0; i < N; ++i) {
    ll a;
    cin >> a;
    if (i == N - 2) {
      a_n1 = a;
    }
    if (i == N - 1) {
      if (N != 1) {
        ans = max(ans, abs(a_n1 - a));
      }
      ans = max(ans, abs(W - a));
    }
  }
  cout << ans << endl;
}
