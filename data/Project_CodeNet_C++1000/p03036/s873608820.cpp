#include <stdio.h>
typedef long long ll;

int main(void) {
  ll i, ans, d, r;
  scanf("%lld%lld%lld", &r, &d, &ans);
  for(i = 0; i < 10; ++i) 
    ans = r * ans - d, printf("%lld\n", ans);
  return 0;
}