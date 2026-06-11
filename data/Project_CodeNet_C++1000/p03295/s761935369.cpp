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

// -------------------------------------------------------
using P = pair<int, int>;
int N, M;

int main() {
  cin >> N >> M;
  vector<P> ba(M);
  rep(i, 0, M) {
    int a, b;
    cin >> a >> b;
    ba[i] = P(b, a);
  }
  sort(ba.begin(), ba.end());

  int ans = 0;
  int last = 0;
  for (auto e : ba) {
    int b = e.first;
    int a = e.second;
    if (a > last) {
      last = b - 1;
      ans++;
    }
  }
  cout << ans << endl;
}
