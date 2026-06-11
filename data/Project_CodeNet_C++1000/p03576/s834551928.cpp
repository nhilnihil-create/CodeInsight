#include <cstdio>
#include <algorithm>

int main()
{
  int n, k;
  scanf("%d%d", &n, &k);
  int x[50], y[50];
  for (int i = 0; i < n; ++i)
  {
    scanf("%d%d", x + i, y + i);
  }
  long long ans = 9e18;
  for (int a = 1; a < n; ++a)
  {
    for (int b = 0; b < a; ++b)
    {
      for (int c = 1; c < n; ++c)
      {
        for (int d = 0; d < c; ++d)
        {
          if (c == d) continue;
          int top = std::max(y[a], y[b]);
          int bottom = y[a] + y[b] - top;
          int left = std::min(x[c], x[d]);
          int right = x[c] + x[d] - left;
          int cnt = 0;
          for (int i = 0; i < n; ++i)
          {
            if (left <= x[i] && x[i] <= right && bottom <= y[i] && y[i] <= top)
            {
              ++cnt;
            }
          }
          if (cnt >= k)
          {
            if (ans > (long long)(right - left) * (long long)(top - bottom))
            {
              ans = (long long)(right - left) * (long long)(top - bottom);
            }
          }
        }
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
