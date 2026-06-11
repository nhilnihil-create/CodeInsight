#include <bits/stdc++.h>
using namespace std;

int	main()
{
  int	a, b, c, x, count = 0;
  
  cin >> a >> b >> c >> x;
  if (x % 50 != 0)
  {
    cout << count << endl;
    return (0);
  }
  for (int i = 0; i <= a; i++)
  {
    for (int j = 0; j <= b; j++)
    {
      if ((i * 500 + j * 100) > x)
        break;
      if ((x - (i * 500 + j * 100)) / 50 > c)
        continue;
      count++;
    }
  }
  cout << count << endl;
  return (0);
}