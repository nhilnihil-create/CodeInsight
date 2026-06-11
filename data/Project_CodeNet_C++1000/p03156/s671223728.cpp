#include <cstdio>
#include <algorithm>

int m[3];

int main()
{
  int n, a, b;
  scanf("%d%d%d", &n, &a, &b);
  for (int i = 0; i < n; ++i)
  {
    int p;
    scanf("%d", &p);
    if (p <= a) m[0]++;
    else if (p <= b) m[1]++;
    else m[2]++;
  }
  printf("%d\n", std::min(m[0], std::min(m[1], m[2])));
  return 0;
}