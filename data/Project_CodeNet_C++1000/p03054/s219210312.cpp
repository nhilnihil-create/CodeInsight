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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll h, w, n, sr, sc;
  cin >> h >> w >> n >> sr >> sc;
  sr--; sc--;
  string s, t;
  cin >> s >> t;

  ll idx_l = 0, idx_r = w-1;
  for (ll i = n-1; i >= 0; i--) {
    if (t[i] == 'R') idx_l = max(idx_l-1, 0LL);
    if (t[i] == 'L') idx_r = min(idx_r+1, w-1);
    if (s[i] == 'R') idx_r--;
    if (s[i] == 'L') idx_l++;
//    cerr << idx_l << " " << idx_r << endl;
    if (idx_l > idx_r || idx_l < 0 || idx_r >= w) {
      puts("NO");
      return 0;
    }
  }
  if (sc < idx_l || idx_r < sc) {
    puts("NO");
    return 0;
  }

  ll idx_u = 0, idx_d = h-1;
  for (ll i = n-1; i >= 0; i--) {
    if (t[i] == 'D') idx_u = max(idx_u-1, 0LL);
    if (t[i] == 'U') idx_d = min(idx_d+1, h-1);
    if (s[i] == 'D') idx_d--;
    if (s[i] == 'U') idx_u++;
//    cerr << idx_u << " " << idx_d << endl;
    if (idx_u > idx_d || idx_u < 0 || idx_d >= h) {
      puts("NO");
      return 0;
    }
  }
  if (sr < idx_u || idx_d < sr) {
    puts("NO");
    return 0;
  }

  puts("YES");
  return 0;
}
