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
using P = pair<int, int>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1001001001;
const long long INFLL = LLONG_MAX / 3;
const double eps = (1e-9);

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  map<int, int> odd, even;
  rep(i, n) {
    int v; cin >> v;
    if (i % 2 == 0) even[v]++;
    else odd[v]++;
  }

  int even_mx = 0;
  int even_mx_num;
  for (auto& p : even) {
    if (p.second > even_mx) {
      even_mx = p.second;
      even_mx_num = p.first;
    }
  }
  int odd_mx = 0;
  int odd_mx_num = 0;
  for (auto& p : odd) {
    if (p.second > odd_mx) {
      odd_mx = p.second;
      odd_mx_num = p.first;
    }
  }

  if (even_mx_num == odd_mx_num) {
    even[even_mx_num] = 0;
    odd[odd_mx_num] = 0;
    int mx = 0;
    for (auto& p : even) chmax(mx, p.second);
    for (auto& p : odd) chmax(mx, p.second);
    cout << n - odd_mx - mx << endl;
  } else {
    cout << n - odd_mx - even_mx << endl;
  }

  return 0;
}
