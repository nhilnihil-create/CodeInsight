#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll n, m;
  cin >> n >> m;
  vector<pair<ll, ll>> p(n);
  for (ll i = 0; i < n; i++)
  {
    ll a, b;
    cin >> a >> b;
    p[i] = make_pair(a, b);
  }
  sort(p.begin(), p.end());
  ll ans = 0;
  ll buf = m;
  for (ll i = 0; i < n; i++)
  {
    if (p[i].second >= buf)
    {
      ans += p[i].first * buf;
      break;
    }
    else
    {
      ans += p[i].first * p[i].second;
      buf -= p[i].second;
    }
  }
  cout << ans << endl;
}
