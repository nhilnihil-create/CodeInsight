#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
using namespace std;

using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1e9;
const long long INFLL = 1LL<<60;

ll calc_num_of_combination(ll n, ll r) {
  ll num = 1;
  for(ll i = 1; i <= r; i++){
    num = num * (n - i + 1) / i;
  }
  return num;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  map<int, int> mp;
  vector<ll> s(n);
  s[0] = a[0] % m;
  mp[s[0]]++;
  for (int i = 1; i < n; i++) {
    s[i] = (s[i-1] + a[i]) % m;
    mp[s[i]]++;
  }

  ll ans = 0;
  for (auto& p : mp) {
    if (p.first == 0) ans += p.second;
    if (p.second >= 2) ans += calc_num_of_combination(p.second, 2);
  }

  cout << ans << endl;

  return 0;
}
