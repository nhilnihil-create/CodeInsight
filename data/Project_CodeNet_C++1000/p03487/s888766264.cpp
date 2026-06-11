#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n, a;
  cin >> n;
  map<ll, ll> mp;
  rep(i, n) {
    cin >> a;
    mp[a]++;
  }

  ll ans = 0;
  for (auto x : mp) {
    ans += (x.first > x.second ? x.second : x.second - x.first);
  }
  cout << ans << endl;
  return 0;
}
