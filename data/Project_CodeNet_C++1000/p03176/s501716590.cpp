#include <bits/stdc++.h>

using namespace std;



int main () {
  int N;
  cin >> N;
  int Size = 1;
  while (Size <= N)
    Size <<= 1;
  vector < long long > Tree (Size << 1);
  vector < int > h(N), a(N);
  for (int i = 0; i < N; ++i)
    cin >> h[i];
  for (int i = 0; i < N; ++i)
    cin >> a[i];
  vector < long long > dp(N + 1);
  for (int flower = 0; flower < N; ++flower) {
    int x = h[flower] + Size;
    long long best = 0;
    while (x > 1) {
      if (x & 1)
        best = max (best, Tree[x - 1]);
      x >>= 1;
    }
    dp[h[flower]] = best + a[flower];
    for (int i = Size + h[flower]; i > 0; i >>= 1)
      Tree[i] = max (Tree[i], dp[h[flower]]);
  }
  long long ans = 0;
  for (int i = 0; i <= N; ++i)
    ans = max (ans, dp[i]);
  cout << ans;
}
