#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n, k, cnt = 0;
  cin >> n >> k;
  vector<ll> a(200005, 0);

  for (int i = 0; i < n; i++)
  {
    ll x;
    cin >> x;
    a.at(x)++;
  }
  for (int i = 0; i < 200005; i++)
  {
    if (a.at(i) != 0)
    {
      cnt++;
    }
  }

  if (cnt <= k)
  {
    cout << 0 << endl;
  }
  else
  {
    sort(a.begin(), a.end());
    ll ans = 0;
    int e = cnt - k;
    for (int i = 0; i < 200005; i++)
    {
      if (a.at(i) > 0)
      {
        ans += a.at(i);
        e--;
      }
      if (e == 0)
      {
        break;
      }
    }
    cout << ans << endl;
  }
}
