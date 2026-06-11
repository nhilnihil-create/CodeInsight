#include <cstdio>
#include <algorithm>

int main()
{
  long long n, k;
  scanf("%lld %lld", &n, &k);
  long long ans = 0;
  if (k == 0)
  {
    printf("%lld\n", n * n);
    return 0;
  }
  for (long long b = k + 1; b <= n; ++b)
  {
    ans += (b - k) * (n / b) + std::max(0LL, (n % b) - k + 1);
  }
  printf("%lld\n", ans);
  return 0;
}