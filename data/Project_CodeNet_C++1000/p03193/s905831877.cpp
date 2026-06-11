#include <cstdio>

int main()
{
  int n, h, w;
  scanf("%d%d%d", &n, &h, &w);
  int ans = 0;
  for (int i = 0; i < n; ++i)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    if (a >= h && b >= w) ++ans;
  }
  printf("%d\n", ans);
  return 0;
}