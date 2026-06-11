#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 5e3 + 10;

int n, A, B, p[N];
ll dp[N];

int main() {
  scanf("%d %d %d", &n, &A, &B);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &p[i]);
  }
  p[++n] = n;
  for (int i = 1; i <= n; i++) {
    dp[i] = (ll) 1e18;
    ll tmp = 0;
    for (int j = i - 1; j >= 0; j--) {
      if (p[j] < p[i]) {
        dp[i] = min(dp[i], dp[j] + tmp);
        tmp += B;
      } else {
        tmp += A;
      }
    }
  }
  printf("%lld\n", dp[n]);
  return 0;
}