#include <cstdio>

int main()
{
  int n;
  scanf("%d", &n);
  int a[100];
  for (int i = 0; i < n; ++i)
  {
    scanf("%d", a + i);
  }
  int ans = 0;
  for (int i = 0; i < n;)
  {
    int* last = a + i;
    while (*last == a[i]) ++i;
    ans += ((a + i) - last) / 2;
  }
  printf("%d\n", ans);
  return 0;
}