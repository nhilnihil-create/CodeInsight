#include <cstdio>

int main()
{
  int n;
  char a[101], b[101], c[101];
  scanf("%d%s%s%s", &n, a, b, c);
  int ans = 0;
  for (int i = 0; i < n; ++i)
  {
    if (a[i] == b[i] && b[i] == c[i]) continue;
    if (a[i] == b[i] || b[i] == c[i] || c[i] == a[i]) ++ans;
    else ans += 2;
  }
  printf("%d\n", ans);
  return 0;
}