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
template<class T> inline void dump(vector<T> v) { for (auto& x : v) cerr << x << " "; cerr << endl; }
template<class T> inline void dump(vector<pair<T, T>> v) { for (auto& p : v) cerr << p.first << " " << p.second << endl; }
template<class T> inline void dump(vector<vector<T>> vv) { for (auto& v : vv) {for (auto& x : v) cerr << x << " "; cerr << endl;} }

constexpr int INF = 1e9+5;
constexpr long long INFLL = 1LL<<60;
constexpr double eps = (1e-9);

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<ll> b; b.reserve((n * (n + 1)) / 2);

  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      ll val = 0;
      for (int k = i; k <= j; k++) {
        val += a[k];
      }
      b.push_back(val);
    }
  }

  sort(b.rbegin(), b.rend());

  int mb = 0;  // 何ビット目が最上位？

  for (int i = 0; i < 64; i++) {
    if ((b[0]>>i) & 1) mb = i;
  }

  vector<ll> c = b;

  for (int i = mb; i >= 0; i--) {
    vector<ll> tmp;  // i 番目のビットが立っている
    for (auto& v : c) if ((v>>i) & 1 == 1) tmp.push_back(v);
    if (tmp.size() >= k) c = tmp;
    else continue;  // この桁は諦めて次へ
  }

  ll ans = c[0];
  for (int i = 0; i < k; i++) {
    ans = (ans & c[i]);
  }

  cout << ans << endl;

  return 0;
}
