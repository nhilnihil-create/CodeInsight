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
int N;
ll A[201010];
ll sum[201010];
ll xorsum[201010];

int main() {
  cin >> N;
  repe(i, 1, N) {
    cin >> A[i];
    sum[i] = sum[i - 1] + A[i];
    xorsum[i] = xorsum[i - 1] ^ A[i];
  }
  A[N + 1] = INF;
  sum[N + 1] = INF;
  xorsum[N + 1] = INF;

  int r = 1;
  ll ans = 0;
  repe(l, 1, N) {
    r = max(r, l);
    ll ssum = sum[r] - sum[l - 1];
    ll xxorsum = xorsum[r] ^ xorsum[l - 1];
    repe(j, r + 1, N + 1) {
      ssum += A[j];
      xxorsum ^= A[j];
      r = j - 1;
      if (ssum != xxorsum) {
        break;
      }
    }
    ans += r - l + 1;
  }

  cout << ans << endl;
}
