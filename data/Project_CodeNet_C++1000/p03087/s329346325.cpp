#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll n, q;
  string s;
  cin >> n >> q >> s;
  vector<ll> v(n, 0);

  for (ll i = 1; i < n; i++)
  {
    if (s[i - 1] == 'A' && s[i] == 'C')
    {
      v[i] = v[i - 1] + 1;
    }
    else
    {
      v[i] = v[i - 1];
    }
  }

  for (ll i = 0; i < q; i++)
  {
    ll l, r;
    cin >> l >> r;
    cout << v[r - 1] - v[l - 1] << endl;
  }
}
