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

// エラトステネスの篩でN 以下の素数判定を行う
// 素数: 1, 素数じゃない: 0
// [0, 0, 1, 1, 0, 1, ...]
vector<int> create_eratos(int n) {
  vector<int> isprime(n+1, 1);
  isprime[0] = 0;
  isprime[1] = 0;

  for (int i = 2; i * i <= n; i++) {
    if (isprime[i]) {
      int j = i + i;
      while (j <= n) {
        isprime[j] = 0;
        j = j + i;
      }
    }
  }
  return isprime;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  auto eratos = create_eratos(1e5+10);

  auto check = [&] (int x) {
    return (x % 2 == 1 && eratos[x] && eratos[(x+1)/2]);
  };

  vector<int> csum(1e5+5, 0);
  for (int i = 3; i <= 1e5+5; i++) {
    csum[i] = csum[i-1];
    if (check(i)) csum[i]++;
  }

  int q;
  cin >> q;

  rep(i, q) {
    int l, r;
    cin >> l >> r;
    cout << csum[r] - csum[l - 1] << endl;
  }

  return 0;
}
