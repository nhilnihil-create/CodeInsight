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
int A, B, C, X;

int main() {
  cin >> A >> B >> C >> X;
  int ans = 0;
  repe(i, 0, A) {
    repe(j, 0, B) {
      repe(k, 0, C) {
        int total = 500 * i + 100 * j + 50 * k;
        if (total == X) {
          ++ans;
        }
      }
    }
  }
  cout << ans << endl;
}
