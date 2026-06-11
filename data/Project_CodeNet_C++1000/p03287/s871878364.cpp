#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
#define sz(x) int(x.size())
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
#define FORV(i, v) for (auto i = v.begin(); i != v.end(); i++)
using namespace std;

using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1001001001;
const long long INFL = LLONG_MAX / 3;
const double eps = (1e-9);

//組み合わせの数nCrを計算
ll calcNumOfCombination(ll n, ll r){
  ll num = 1;
  for(ll i = 1; i <= r; i++){
    num = num * (n - i + 1) / i;
  }
  return num;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  rep(i, n) {
    cin >> a[i];
    a[i] %= m;
  }
  vector<ll> s(n+1, 0);
  rep(i, n) {
    s[i+1] = (s[i] + a[i]) % m;
  }
  map<ll, ll> mp;
  for (auto& v : s) {
    mp[v]++;
  }
  ll ans = 0;
  for (auto& p : mp) {
    if (p.second > 1) ans += calcNumOfCombination(p.second, 2);
  }

  cout << ans << endl;

  return 0;
}
