#include <bits/stdc++.h>

using namespace std;

int main()
{
  int a, b, c, x, y, ans = 0;

  scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);

  if (a + b > c * 2)
  {
    if (x > y)
    {
      ans += y * c * 2;
      ans += a * (x - y);

      if (a > 2 * c)
      {
        ans = 0;

        ans += x * 2 * c;
      }
    }
    else
    {
      ans += x * c * 2;
      ans += b * (y - x);

      if (b > 2 * c)
      {
        ans = 0;

        ans += y * 2 * c;
      }
    }
  }
  else
  {
    ans += a * x;
    ans += b * y;
  }

  printf("%d", ans);
}