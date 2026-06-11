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
int A[10];

int main() {
  cin >> A[0] >> A[1] >> A[2];
  int ans = inf;
  vector<int> perm = {0, 1, 2};
  do {
    int t0 = A[perm[0]];
    int t1 = A[perm[1]];
    int t2 = A[perm[2]];
    chmin(ans, abs(t1 - t0) + abs(t2 - t1));
  } while (next_permutation(perm.begin(), perm.end()));
  cout << ans << endl;
}