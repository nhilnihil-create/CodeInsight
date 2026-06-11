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
int Q;
int num[101010];
int l[101010], r[101010];
bool is_prime[101010];

void prime_init() {
  repe(i, 2, 100000) { is_prime[i] = true; }
  repe(i, 2, 100000) {
    if (is_prime[i]) {
      for (int j = i + i; j <= 100000; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

int main() {
  prime_init();
  num[2] = 0;
  repe(i, 3, 100000) {
    if (is_prime[i] && is_prime[(i + 1) / 2]) {
      num[i] = num[i - 1] + 1;
    } else {
      num[i] = num[i - 1];
    }
  }

  cin >> Q;
  rep(i, 0, Q) { cin >> l[i] >> r[i]; }
  rep(i, 0, Q) { cout << num[r[i]] - num[l[i] - 1] << endl; }
}
