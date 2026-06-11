#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll n, m;
  cin >> n >> m;
  ll l, r;
  l = 0;
  r = 1e9 + 7;
  for (ll i = 0; i < m; i++)
  {
    ll a, b;
    cin >> a >> b;
    l = max(l, a);
    r = min(r, b);
  }
  if (r >= l)
  {
    cout << r - l + 1 << endl;
  }
  else
  {
    cout << 0 << endl;
  }
}
