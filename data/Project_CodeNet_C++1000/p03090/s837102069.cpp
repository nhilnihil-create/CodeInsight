#include <stdio.h>
typedef long long ll;

int main(void) {
  ll i, j, n;
  scanf("%lld", &n);
  if(n & 1) {
    printf("%lld\n", (n - 1) * (n - 1) / 2);
    for(i = 1; i < n; ++i) 
      for(j = i + 1; j <= n; ++j) if(i + j != n) printf("%lld %lld\n", i, j);
  } else {
    printf("%lld\n", n * (n - 2) / 2);
    for(i = 2; i < n; ++i) printf("1 %lld\n", i);
    for(i = 2; i < n; ++i)
      for(j = i + 1; j <= n; ++j) if(i + j != n + 1) printf("%lld %lld\n", i, j);
  }
  return 0;
}