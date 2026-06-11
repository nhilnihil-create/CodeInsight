#include <cstdio>
#include <algorithm>

int main()
{
  long long a, b, k;
  scanf("%lld%lld%lld", &a, &b, &k);
  
  long long *p = &a, *q = &b;
  while (k-- > 0)
  {
    *p /= 2;
    *q += *p;
    std::swap(p, q);
  }
  printf("%lld %lld\n", a, b);
  return 0;
}