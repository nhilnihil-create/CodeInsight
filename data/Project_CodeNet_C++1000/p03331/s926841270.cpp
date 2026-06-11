#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, ans = 100000000;

  scanf("%d", &n);

  int a, b, sumA, sumB;

  for (int i = 1; i <= n / 2; i++)
  {
    sumA = 0;
    sumB = 0;
    a = i;
    b = n - i;

    while (a != 0)
    {
      sumA += a % 10;
      a /= 10;
    }

    while (b != 0)
    {
      sumB += b % 10;
      b /= 10;
    }
    if (ans > sumA + sumB)
      ans = sumA + sumB;
  }

  printf("%d", ans);
}