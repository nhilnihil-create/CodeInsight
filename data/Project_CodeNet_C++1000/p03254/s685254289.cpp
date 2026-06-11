#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
  int n,x;
  int count=0;
  cin >> n >> x;
  int a[n];

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  sort(a,a+n);

  for (int i = 0; i < n; i++)
  {
    x = x - a[i];
    if (x<0)
    {
      break;
    }else if(x==0)
    {
      count++;
      break;
    }
    count++; 
  }
  if (x>0)
  {
    count--;
  }
  
  

  cout << count << "\n";

  return 0;
}