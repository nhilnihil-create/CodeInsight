#include <cstdio>

int main()
{
  char s[5];
  scanf("%s", s);
  int ans = 0;
  for (int i = 0; i < 4; ++i)
  {
    if (s[i] == '2') ++ans;
  }
  printf("%d\n", ans);
  return 0;
}
