#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  int n,m,x;
  cin >> n >> m >> x;
  int a[m];
  
  for (int i = 0; i < m; i++)
  {
    cin >> a[i];
  }
  

  int addcount=0;
  int x2=x;
  while (x2<n)
  {
    x2++;
    for (int i = 0; i < m; i++)
    {
      if (a[i]==x2)
      {
        addcount++;
      }
    }
  }

  int deccount=0;
  x2=x;
  while (x2!=0)
  {
    x2--;
    for (int i = 0; i < m; i++)
    {
      if (a[i]==x2)
      {
        deccount++;
      }
    }
  }
  if (addcount < deccount)
  {
    cout << addcount << "\n";
  }else
  {
    cout << deccount << "\n";
  }
  return 0;
}