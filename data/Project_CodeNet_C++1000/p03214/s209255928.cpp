#include <cstdio>
#include <cstdlib>

int main()
{
  int n;
  scanf("%d", &n);
  int sum = 0;
  int a[100];
  for (int i = 0; i < n; ++i)
  {
    scanf("%d", a + i);
    sum += a[i];
  }
  int ans = 0;
  int mind = 1e9;
  for (int i = 0; i < n; ++i)
  {
    if (std::abs(sum - n * a[i]) < mind)
    {
      ans = i;
      mind = std::abs(sum - n * a[i]);
    }
  }
  printf("%d\n", ans);
  return 0;
}