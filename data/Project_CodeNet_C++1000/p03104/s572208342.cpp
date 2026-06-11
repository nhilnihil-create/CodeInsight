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
const long long INFLL = LLONG_MAX / 3;
const double eps = (1e-9);

// 0 から a までの 0 xor 1 xor ... xor a を求める
ll foo(ll a) {
  if (a % 2 != 0) {
    if (((a+1) / 2) % 2 == 0) return 0;
    else return 1;
  }
  if ((a+1) / 2 % 2 == 0) return a;
  else return 1 ^ a;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll a, b;
  cin >> a >> b;;
  ll ans = foo(b) ^ foo(a-1);

  cout << ans << endl;

  return 0;
}
