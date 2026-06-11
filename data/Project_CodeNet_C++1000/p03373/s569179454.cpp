#include <bits/stdc++.h>

using namespace std;

int main()
{
  int a, b, c, x, y, ans = 1000000001;

  scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);

  int ab = c * 2;

  for (int i = 0; i <= 100000; i++)
  {
    ans = min(ans, ab * i + a * max(0, x - i) + b * max(0, y - i));
  }

  printf("%d", ans);
}