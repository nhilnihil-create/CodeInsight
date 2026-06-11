#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
  int n,d,x;
  cin >> n >> d >> x;
  int a[n];
  int choco=n;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  for (int i = 1; i < d; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i%a[j]==0)
      {
        choco++;
      } 
    }
  }
  

  cout << choco+x << "\n";

  return 0;
}