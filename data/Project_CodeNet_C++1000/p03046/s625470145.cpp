#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int pow(int x, int n)
{
  int ret = 1;
  while (n > 0)
  {
    if (n & 1)
      ret = ret * x;
    x = x * x;
    n >>= 1;
  }
  return ret;
}

int main()
{
  int m, k;
  cin >> m >> k;
  int m2 = pow(2, m);
  if (m2 <= k)
  {
    printf("-1\n");
    return 0;
  }
  if (m == 1)
  {
    if (k == 0)
      printf("1 0 0 1\n");
    else
      printf("-1\n");
    return 0;
  }
  for (int i=m2-1; i>=0; i--)
    if (i != k)
      printf("%d ", i);
  printf("%d ", k);
  rep(i, m2)
    if (i != k)
      printf("%d ", i);
  printf("%d\n", k);
  return 0;
}