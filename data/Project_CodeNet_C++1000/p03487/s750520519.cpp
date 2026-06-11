#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll n, ans = 0;
  cin >> n;
  vector<ll> a(n);
  map<ll, ll> b;
  for (ll i = 0; i < n; i++)
  {
    cin >> a.at(i);
    b[a.at(i)]++;
  }

  for (auto itr = b.begin(); itr != b.end(); itr++)
  {
    if (itr->first != itr->second)
    {
      if (itr->first > itr->second)
      {
        ans += itr->second;
      }
      else
      {
        ans += abs(itr->first - itr->second);
      }
    }
  }
  cout << ans << endl;
}
