#include <cstdio>

int c[4];

int main()
{
  for (int i = 0; i < 3; ++i)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    c[a]++; c[b]++;
    if (c[a] >= 3 || c[b] >= 3)
    {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  return 0;
}