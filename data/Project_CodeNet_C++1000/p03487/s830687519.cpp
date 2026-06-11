#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

const double pi = 3.141592653589793;
// -------------------------------------------------------
vector<int> a;
int N;
map<int, int> cnt;

int main() {
  cin >> N;
  rep(i, 0, N) {
    int t;
    cin >> t;
    a.push_back(t);
    ++cnt[t];
  }
  ll ans = 0;
  for (auto e : cnt) {
    int n = e.first;
    int c = e.second;
    if (c >= n) {
      ans += c - n;
    } else {
      ans += c;
    }
  }
  cout << ans << endl;
}
