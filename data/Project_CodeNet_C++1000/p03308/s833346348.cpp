#include <bits/stdc++.h>
using namespace std;

int	main()
{
  int	n, min_v, max_v, temp;
  
  cin >> n;
  cin >> min_v;
  max_v = min_v;
  for (int i = 1; i < n; i++)
  {
    cin >> temp;
    if (temp < min_v)
      min_v = temp;
    else if (max_v < temp)
      max_v = temp;
  }
  cout << max_v - min_v << endl;
  return (0);
}