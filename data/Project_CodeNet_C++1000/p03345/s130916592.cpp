#include <cstdio>
#define ll long long

int main() {
  ll a, b, c, k;
  scanf("%lld %lld %lld %lld", &a, &b, &c, &k);
  if(a - b < -1000000000000000000 || 1000000000000000000 < a - b)
    printf("Unfair\n");
  else
    printf("%lld\n", (a - b) * (1 - k % 2 * 2));
}