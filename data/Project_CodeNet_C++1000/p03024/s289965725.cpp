#include <cstdio>

int main()
{
  char s[16];
  scanf("%s", s);
  int x = 0;
  for (char *p = s; *p; ++p)
  {
    if (*p == 'x') ++x;
  }
  puts(x < 8 ? "YES" : "NO");
  return 0;
}