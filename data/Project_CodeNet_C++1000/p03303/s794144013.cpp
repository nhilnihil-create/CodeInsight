#include <cstdio>
#include <cstring>

int main()
{
  char s[1001];
  int w;
  scanf("%s%d", s, &w);
  int len = strlen(s);
  for (int i = 0; i < len; i += w)
  {
    putchar(s[i]);
  }
  putchar('\n');
  return 0;
}