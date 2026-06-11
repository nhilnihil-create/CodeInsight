#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, ans = 1 << 30;
  cin >> n;
  for (int i = 1; i < n; i++)
  {
    int a = i, b = n - i, tmp = 0;
    while (a > 0)
    {
      tmp += a % 10;
      a /= 10;
    }
    while (b > 0)
    {
      tmp += b % 10;
      b /= 10;
    }
    ans = min(ans, tmp);
  }
  cout << ans << endl;
}