#include <bits/stdc++.h>
using namespace std;

int	main()
{
  int	n, a, b, t_sum, sum = 0;
  
  cin >> n >> a >> b;
  for (int i = 1; i <= n; i++)
  {
    t_sum = 0;
    for (int j = i; j > 0; j = j / 10)
    {
      t_sum += j % 10;
    }
    if (a <= t_sum && t_sum <= b)
      sum += i;
  }
  cout << sum << endl;
  return (0);
}