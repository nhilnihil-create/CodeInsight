#include <cstdio>

int main()
{
  long long x, y;
  scanf("%lld%lld", &x, &y);
  if (x % y == 0)
  {
    puts("-1");
    return 0;
  }
  printf("%lld\n", x * (y - 1));
  return 0;
}