#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
#define DUMP(v) for(auto& x : v) cerr << x << " "; cerr << endl;
using namespace std;

using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
constexpr int INF = 1e9+5;
constexpr long long INFLL = 1LL<<60;
constexpr double eps = (1e-9);

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int x, y, z, k;
  cin >> x >> y >> z >> k;
  vector<ll> a(x), b(y), c(z);

  rep(i, x) cin >> a[i];
  rep(i, y) cin >> b[i];
  rep(i, z) cin >> c[i];

  vector<ll> bc(y * z);
  rep(i, y) {
    rep(j, z) {
      bc.push_back(b[i] + c[j]);
    }
  }

  sort(bc.rbegin(), bc.rend());
  bc.resize(min(3000, int(bc.size())));

  vector<ll> abc;
  rep(i, x) {
    rep(j, bc.size()) {
      abc.push_back(a[i] + bc[j]);
    }
  }

  sort(abc.rbegin(), abc.rend());

  rep(i, k) {
    cout << abc[i] << endl;
  }

  return 0;
}
