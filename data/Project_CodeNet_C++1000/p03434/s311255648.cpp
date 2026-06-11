#include <bits/stdc++.h>
using namespace std;

int	main()
{
  int	n, a = 0, b = 0;
  
  cin >> n;
  vector<int>	v(n);
  
  for (int i = 0; i < n; i++)
    cin >> v.at(i);
  sort(v.begin(), v.end(), greater<int>());
  int	i;
  for (i = 0; i < n - 1; i += 2)
  {
    a += v.at(i);
    b += v.at(i + 1);
  }
  if (i == v.size() - 1)
    a += v.at(i);
  cout << a - b << endl;
  return (0);
}