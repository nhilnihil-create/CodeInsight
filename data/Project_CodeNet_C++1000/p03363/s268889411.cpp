#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  ll n, ans = 0;
  cin >> n;
  vector<ll> a(n), s(n + 1, 0);
  map<ll, ll> mp;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    s[i + 1] = a[i] + s[i];
    mp[s[i+1]]++;
  }
  mp[s[0]]++;

  for (auto m : mp)
    ans += m.second * (m.second - 1) / 2;

  cout << ans << endl;
  return 0;
}
