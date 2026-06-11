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
int N;

int main() {
  cin >> N;
  int pt = 0;
  int px = 0;
  int py = 0;
  rep(i, 0, N) {
    int t, x, y;
    cin >> t >> x >> y;
    int dt = abs(t - pt);
    int dx = abs(x - px);
    int dy = abs(y - py);
    int dist = dx + dy;

    if (dist > dt) {
      cout << "No" << endl;
      return 0;
    }
    if (dist % 2 != dt % 2) {
      cout << "No" << endl;
      return 0;
    }
    pt = t;
    px = x;
    py = y;
  }
  cout << "Yes" << endl;
  return 0;
}
