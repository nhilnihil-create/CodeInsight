#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll n, k;
  cin >> n >> k;
  vector<ll> x(n);
  for (ll i = 0; i < n; i++)
  {
    cin >> x[i];
  }

  ll ans = 1e9 + 7;
  for (ll i = 0; i < n - k + 1; i++)
  {
    ll buf;
    buf = min(abs(0 + x[i]) + abs(x[i] - x[i + k - 1]), abs(0 + x[i + k - 1]) + abs(x[i + k - 1] - x[i]));
    ans = min(ans, buf);
  }
  cout << ans << endl;
}
