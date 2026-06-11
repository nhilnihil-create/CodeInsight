#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll = long long;

const double PI = 3.14159265358979;

void solve()
{
  ll n;
  cin >> n;
  string s;
  map<char, ll> mp;
  for(int i = 0; i < n; ++i)
  {
    cin >> s;
    mp[s[0]]++;
  }

  vector<ll> p;
  if (mp['M'] > 0) p.emplace_back(mp['M']);
  if (mp['A'] > 0) p.emplace_back(mp['A']);
  if (mp['R'] > 0) p.emplace_back(mp['R']);
  if (mp['C'] > 0) p.emplace_back(mp['C']);
  if (mp['H'] > 0) p.emplace_back(mp['H']);

  ll num = p.size();
  ll ans = 0;
  for(int i1 = 0; i1 < num - 2; ++i1)
  {
    for(int i2 = i1 + 1; i2 < num - 1; ++i2)
    {
      for(int i3 = i2 + 1; i3 < num; ++i3)
      {
        ans += p[i1] * p[i2] * p[i3];
      }
    }
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}