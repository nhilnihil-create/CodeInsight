#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const int inf = INT_MAX;
const int MOD = 1000000007;
const long long INF = LLONG_MAX;
const long long MINF = LLONG_MIN;

// -------------------------------------------------------

int N;
int a[100];

int main() {
  cin >> N;
  int maxa = -inf;
  int maxi = 0;
  int mina = inf;
  int mini = 0;
  repe(i, 1, N) {
    cin >> a[i];
    if (chmax(maxa, a[i])) {
      maxi = i;
    }
    if (chmin(mina, a[i])) {
      mini = i;
    }
  }

  if (abs(maxa) > abs(mina)) {
    cout << 2 * N - 2 << "\n";
    repe(i, 1, N) {
      if (i == maxi) continue;

      cout << maxi << " " << i << "\n";
    }

    repe(i, 1, N - 1) { cout << i << " " << i + 1 << "\n"; }
  } else {
    cout << 2 * N - 2 << "\n";
    repe(i, 1, N) {
      if (i == mini) continue;

      cout << mini << " " << i << "\n";
    }

    for (int i = N; i >= 2; --i) {
      cout << i << " " << i - 1 << "\n";
    }
  }
}
