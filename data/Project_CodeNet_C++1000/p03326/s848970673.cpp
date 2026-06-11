#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())

using namespace std;
typedef int64_t ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1001001001;
const long long INFL = (1LL<<60);
const double eps = (1e-9);

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  vector<vector<ll>> sums(8, vector<ll>(n, 0));
  rep(i, n) {
    ll x, y, z;
    cin >> x >> y >> z;
    sums[0][i] += (x + y + z);
    sums[1][i] += (x + y - z);
    sums[2][i] += (x - y + z);
    sums[3][i] += (x - y - z);
    sums[4][i] += (-x + y + z);
    sums[5][i] += (-x + y - z);
    sums[6][i] += (-x - y + z);
    sums[7][i] += (-x - y - z);
  }

  rep(i, 8) {
    sort(ALL(sums[i]), greater<ll>());
  }

  ll ans = 0;
  rep(i, 8) {
    ll tmp = 0;  
    rep(j, m) {
      tmp += sums[i][j];
    }
    chmax(ans, tmp);
  }

  cout << ans << endl;  

  return 0;
}
