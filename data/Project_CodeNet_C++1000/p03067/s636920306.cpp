#include <cstdio>

int main()
{
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  puts((a <= c && c <= b) || (b <= c && c <= a) ? "Yes" : "No");
  return 0;
}