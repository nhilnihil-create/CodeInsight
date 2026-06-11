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
int A, B, C;

int main() {
  cin >> A >> B >> C;
  int ans = inf;
  for (int i = 0; i <= 26; ++i) {
    for (int j = 0; j <= 26; ++j) {
      for (int k = 0; k <= 26; ++k) {
        int a = A + 2 * i;
        int b = B + 2 * j;
        int c = C + 2 * k;
        int aans = i + j + k;
        int mi = min(a, min(b, c));
        aans += a - mi;
        aans += b - mi;
        aans += c - mi;
        chmin(ans, aans);
      }
    }
  }
  cout << ans << endl;
}