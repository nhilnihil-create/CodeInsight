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

int N, K;
map<int, int> mp;

int main() {
  cin >> N >> K;
  rep(i, 0, N) {
    int a;
    cin >> a;
    mp[a]++;
  }

  vector<pair<int, int>> v;
  for (auto e : mp) {
    v.push_back(make_pair(e.second, e.first));
  }
  sort(v.begin(), v.end());

  int diff = v.size() - K;
  if (diff <= 0) {
    cout << 0;
    return 0;
  }

  int ans = 0;
  rep(i, 0, diff) { ans += v[i].first; }

  cout << ans << endl;
}