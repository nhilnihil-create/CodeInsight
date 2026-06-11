#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, a, b, count = 0;
  cin >> n >> a >> b;

  for (int i = 1; i <= n; i++)
  {
    if (i < 10 && a <= i && i <= b)
    {
      count += i;
      continue;
    }

    int buf = i;
    int dig, S = 0;

    while (buf)
    {
      dig = buf % 10;
      S += dig;
      buf /= 10;
    }

    if (a <= S && S <= b)
    {
      count += i;
    }
  }
  cout << count << endl;
}
