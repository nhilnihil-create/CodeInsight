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
bool is_prime[101010];
bool is_1_mod5[101010];

int main() {
  cin >> N;
  rep(i, 0, 100000) { is_prime[i] = true; }
  rep(i, 2, 60000) {
    if (i % 5 == 1) is_1_mod5[i] = true;
    if (!is_prime[i]) continue;

    for (int j = 2 * i; j <= 60000; j += i) {
      is_prime[j] = false;
    }
  }

  int cnt = 0;
  rep(i, 2, 60000) {
    if (cnt == N) return 0;

    if (is_prime[i] && is_1_mod5[i]) {
      if (cnt != 0) cout << " ";

      cout << i;
      cnt++;
    }
  }
}
