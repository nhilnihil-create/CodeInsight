#include <bits/stdc++.h>
using namespace std;

int	main()
{
  int	n, flag = 0;
  
  cin >> n;
  for (int i = 0; i * 7 <= n; i++)
  {
    if (flag == 1)
      break;
    for (int j = 0; j * 4 + i * 7 <= n; j++)
    {
      if (j * 4 + i * 7 == n)
      {
        flag = 1;
        break ;
      }
    }
  }
  if (flag == 1)
    cout << "Yes\n";
  else
    cout << "No\n";
  return (0);
}