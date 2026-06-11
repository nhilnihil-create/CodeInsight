#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef unsigned long long ULong;

const int MOD = round(1e9 + 7);
const int N = 1e5 + 5;

Long fact[N];
Long ways_to_be_placed_after_less_numbers[N];
Long ways_y[N];

Long power(int b, int p) {
  if (p == 0) return 1;
  Long tmp = power(b, p / 2);
  tmp = 1LL * tmp * tmp % MOD;
  if (p & 1) {
    tmp = 1LL * tmp * b % MOD;
  }
  return tmp;
}

int n;

void build() {
  fact[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = 1LL * fact[i - 1] * i % MOD;
  }

  for (int i = 1; i <= n; ++i) {
    ways_to_be_placed_after_less_numbers[i] = 1LL * fact[n] * power(i, MOD - 2)
      % MOD;
  }

  ways_y[2] = ways_to_be_placed_after_less_numbers[2];
  for (int i = 3; i <= n; ++i) {
    ways_y[i] = (ways_y[i - 1] + ways_to_be_placed_after_less_numbers[i]) % MOD;
  }
}

Long arr[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> n;
  build();

  Long res = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    res = (res
      + 1LL * arr[i]
        * (ways_y[i] + ways_y[n - i + 1]
          + ways_to_be_placed_after_less_numbers[1])) % MOD;
  }
  cout << res;

}

