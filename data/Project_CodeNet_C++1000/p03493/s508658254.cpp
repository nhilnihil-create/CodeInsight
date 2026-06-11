#include <bits/stdc++.h>
using namespace std;

int	main()
{
  string	str;
  int		c = 0;
  
  cin >> str;
  for(int i = 0; i < 3; i++)
    if (str.at(i) == '1')
      c++;
  cout << c << endl;
  return (0);
}
