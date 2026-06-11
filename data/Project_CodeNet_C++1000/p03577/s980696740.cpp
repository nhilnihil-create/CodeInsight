#include <cstdio>
#include <cstring>

int main()
{
  char s[51];
  scanf("%s", s);
  printf("%.*s\n", strlen(s) - 8, s);
  return 0;
}