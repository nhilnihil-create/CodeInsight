#include <cstdio>

int main()
{
  int n;
  char s[101];
  scanf("%d%s", &n, s);
  int r = 0;
  for (char *p = s; *p; ++p)
  {
    if (*p == 'R') ++r;
  }
  puts(r > n - r ? "Yes" : "No");
  return 0;
}
    