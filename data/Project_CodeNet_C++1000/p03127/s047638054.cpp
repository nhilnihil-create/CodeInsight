#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (ll i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  while (1)
  {
    sort(a.begin(), a.end());
    for (ll i = 1; i < a.size(); i++)
    {
      a[i] %= a[0];
      if (a[i] == 0)
      {
        a.erase(a.begin() + i);
      }
    }
    if (a.size() == 1)
    {
      break;
    }
  }
  cout << a[0] << endl;
}
