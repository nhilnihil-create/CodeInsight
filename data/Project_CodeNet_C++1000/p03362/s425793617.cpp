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

vector<int> create_prime_list(int n) {
  vector<int> eratos = create_eratos(n);
  vector<int> result;
  result.reserve(n);
  for (int i = 1; i <=n; i++) {
    if (eratos[i]) {
      result.push_back(i);
    }
  }
  return result;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<int> prime_numbers = create_prime_list(55555);

  vector<int> ans;
  for (auto& x : prime_numbers) {
    if (x % 5 == 1) ans.push_back(x);
    if (ans.size() == n) break;
  }

  for (auto& x : ans) cout << x << " "; cout << endl;

  return 0;
}
