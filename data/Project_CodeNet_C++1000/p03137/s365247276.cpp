#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll n, m;
  cin >> n >> m;
  vector<ll> x(m);
  vector<ll> y(m - 1);

  if (n >= m)
  {
    cout << 0 << endl;
    return 0;
  }

  for (ll i = 0; i < m; i++)
  {
    cin >> x[i];
  }
  sort(x.begin(), x.end());

  if (n == 1)
  {
    cout << abs(x[m - 1] - x[0]) << endl;
    return 0;
  }

  for (ll i = 0; i < m - 1; i++)
  {
    y[i] = abs(x[i] - x[i + 1]);
  }
  sort(y.begin(), y.end());

  ll ans = 0;
  for (ll i = 0; i < m - n; i++)
  {
    ans += y[i];
  }
  cout << ans << endl;
}
