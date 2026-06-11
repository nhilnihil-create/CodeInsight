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
ll N;
ll A[201010];

int main() {
  cin >> N;
  rep(i, 0, N) {
    ll a;
    cin >> a;
    A[i] = a - (i + 1);
  }
  sort(A, A + N);

  ll mid = (N + 1) / 2;
  ll b = A[mid - 1];

  ll ans = 0;
  rep(i, 0, N) { ans += abs(A[i] - b); }
  cout << ans << endl;
}