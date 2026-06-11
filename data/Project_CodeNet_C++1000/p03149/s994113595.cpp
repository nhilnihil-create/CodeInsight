#include <cstdio>

int main()
{
  int a = 0;
  for (int i = 0; i < 4; ++i)
  {
    int b;
    scanf("%d", &b);
    a |= (1 << b);
  }
  puts(a == 658 ? "YES" : "NO");
  return 0;
}