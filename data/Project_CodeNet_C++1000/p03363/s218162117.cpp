#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define repr(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define ALL(a) (a).begin(), (a).end()
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;
const int dx[] = {0, 1, -1, 0};
const int dy[] = {1, 0, 0, -1};
const ll mod = 1e9 + 7;
const ll INF = 1e9;
const ll LINF = 1LL << 60;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////
  int n;
  cin >> n;
  vector<ll> a(n), s(n + 1, 0);
  rep(i, n) cin >> a[i];
  rep(i, n) s[i + 1] = s[i] + a[i];
  map<ll, ll> mp;
  rep(i, n + 1) mp[s[i]]++;
  ll ans = 0;
  for (auto x : mp) ans += x.second * (x.second - 1) / 2;
  cout << ans << endl;
  return 0;
}
