#include <bits/stdc++.h>
using namespace std;

int	main()
{
  string	str;
  int		c = 0;
  
  cin >> str;
  for(int i = 0; i < 3; i++)
    if (str.at(i) == 'o')
      c++;
  cout << (700 + c * 100) << endl;
  return (0);
}
