#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);
  vector<ll> s(n + 1, 0);
  rep(i, n) s.at(i + 1) = s.at(i) + a.at(i);
  map<ll, ll> mp;
  rep(i, n) s.at(i + 1) = s.at(i) + a.at(i);
  rep(i, n + 1) mp[s.at(i)]++;
  ll ans = 0;
  for (auto p : mp)
  {
    ll v = p.second;
    if (v < 2)
    {
      continue;
    }
    ans += v * (v - 1) / 2;
  }
  cout << ans << endl;
}