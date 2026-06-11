#include <bits/stdc++.h>
using namespace std;

int	main()
{
  int		n, t, a, h, i, index = 1;
  double	diff;
  
  cin >> n >> t >> a;
  cin >> h;
  diff = abs((t - h * 0.006) - a);
  for (i = 1; i < n; i++)
  {
    cin >> h;
    if (abs((t - h * 0.006) - a) < diff)
    {
      diff = abs((t - h * 0.006) - a);
      index = i + 1;
    }
  }
  cout << index << endl;
  return (0);
}