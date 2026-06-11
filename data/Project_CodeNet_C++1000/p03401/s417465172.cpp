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
int A[201010];

int main() {
  cin >> N;
  int sum = 0;
  repe(i, 1, N) {
    cin >> A[i];
    sum += abs(A[i] - A[i - 1]);
  }
  sum += abs(0 - A[N]);

  repe(i, 1, N) {
    int ans = sum;
    ans -= abs(A[i] - A[i - 1]);
    ans -= abs(A[i + 1] - A[i]);
    ans += abs(A[i + 1] - A[i - 1]);
    cout << ans << "\n";
  }
}
