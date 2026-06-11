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
ll N, M;

int main() {
  cin >> N >> M;
  if (N == 1 && M == 1) {
    cout << 1 << endl;
    return 0;
  }

  if (N == 1) {
    cout << M - 2 << endl;
    return 0;
  }

  if (M == 1) {
    cout << N - 2 << endl;
    return 0;
  }

  cout << (N - 2) * (M - 2) << endl;
}