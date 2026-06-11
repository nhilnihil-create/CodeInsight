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
const long long INFL = 1LL<<60;


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n; cin >> n;
  vector<int> v(n);
  rep(i, n) cin >> v[i];
  map<int, int> mp_e, mp_o;
  rep(i, n) {
    if (i % 2 == 0) mp_e[v[i]]++;
    else mp_o[v[i]]++;
  }

  vector<pair<int, int>> ve, vo;
  for (auto& p : mp_e) ve.emplace_back(p.second, p.first);
  for (auto& p : mp_o) vo.emplace_back(p.second, p.first);

  sort(ALL(ve));
  reverse(ALL(ve));
  sort(ALL(vo));
  reverse(ALL(vo));

  ll ans = 0;
  if (ve[0].second != vo[0].second) {
    ans = n - ve[0].first - vo[0].first;
  } else {
    if (ve.size() == 1 && vo.size() == 1) {
      ans = n - ve[0].first;
    } else if (ve.size() == 1) {
      ans = n - ve[0].first - vo[1].first;
    } else if (vo.size() == 1) {
      ans = n - ve[1].first - vo[0].first;
    } else {
      ans = n - ve[0].first - vo[1].first;
      chmin(ans, ll(n - vo[0].first - ve[1].first));
    }
  }

  cout << ans << endl;

  return 0;
}
