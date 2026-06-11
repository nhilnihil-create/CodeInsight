#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200000;
int64_t n, x;
int pos[MAX_N];
uint64_t pre_sum[MAX_N+1];

__int128 e(uint64_t i, uint64_t x)
{
  if (i == 1) return (__int128)5*x;
  return (__int128)(2*i + 1) * x;
}

int ceil(int x, int y)
{
  if (x % y == 0) return x/y;
  return x/y + 1;
}

int main()
{
  cin >> n >> x;
  for (int i = 0; i < n; ++i) cin >> pos[i];

  pre_sum[0] = 0;
  for (int i = 0; i < n; ++i) {
    pre_sum[i+1] = pre_sum[i] + pos[i];
  }

  __int128 min_e = ULLONG_MAX;
  for (int k = 1; k <= n; k++) {
    __int128 total_e = (n+k) * x;
    for (int i = n-1; i >= 0; i -= k) {
      int l = max(0, i-k+1);
      total_e += e(ceil(n-i, k), pre_sum[i+1] - pre_sum[l]);
    }
    min_e = min(min_e, total_e);
  }

  cout << (uint64_t)min_e << endl;

  return 0;
}
