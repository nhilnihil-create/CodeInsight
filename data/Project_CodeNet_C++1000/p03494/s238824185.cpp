#include <bits/stdc++.h>
using namespace std;

int	main()
{
  int			n;
  int			i = -1;
  int			counter = 0;
  int			odd_flag = 0;
  
  cin >> n;
  vector<int>	vec(n);

  while (++i < n)
    cin >> vec.at(i); 
  while (1)
  {
    i = 0;
    while (i < n)
    {
      if (vec.at(i) % 2 == 0)
        vec.at(i) /= 2;
      else
      {
        odd_flag = 1;
        break ;
      }
      i++;
    }
    if (odd_flag == 1)
      break ;
    counter++;
  }
  cout << counter << endl;
}