#include <bits/stdc++.h>
using namespace std;

const int N = 201000;

int n;
long long X, a[N], s[N];

int main(void) {
  scanf("%d%lld", &n, &X);
  for(int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    s[i] = s[i - 1] + a[i];
  }
  __int128 Ans = s[n] * 5 + n * X;
  for(int i = 1; i <= n; i++) {
    __int128 now = 0;
    int num = n / i, res = n % i, j, tmp = 2 * num + 3;
    now += s[res] * tmp; tmp -= 2;
    for(j = res; j < n; j += i, tmp -= 2)
      now += (s[min(j + i, n)] - s[j]) * max(tmp, 5);
    Ans = min(Ans, now + i * X);
  }
  printf("%lld\n", Ans + n * X);
}
