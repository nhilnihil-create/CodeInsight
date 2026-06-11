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

  int n;
  cin >> n;

  vector<int> c(n-1), s(n-1), f(n-1);
  rep(i, n-1) cin >> c[i] >> s[i] >> f[i];

  for (int i = 0; i < n-1; i++) {
    ll ans = 0;
    for (int j = i; j < n-1; j++) {
      if (ans <= s[j]) {  // 始発が未だ
        ans = s[j] + c[j];   // 始発に乗って次へ
      } else {
        if (ans % f[j] == 0) ans += c[j];
        else ans += (f[j] - ans % f[j]) + c[j];
      }
    }

    cout << ans << endl;
  }

  cout << 0 << endl;

  return 0;
}
