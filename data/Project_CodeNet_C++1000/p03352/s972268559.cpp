#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t x;
  cin >> x;
  int64_t ans = 1;
  for (int b = 1; b <= 1000; b++)
  {
    for (int p = 2; p <= 10; p++)
    {
      int64_t i = pow(b, p);
      if (i > x)
        break;
      ans = max(ans, i);
    }
  }
  cout << ans << endl;
}