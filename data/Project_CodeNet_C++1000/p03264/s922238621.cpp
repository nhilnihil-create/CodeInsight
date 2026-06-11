#include<iostream>
using namespace std;
int main()
{
  int k, t = 0;
  cin >> k;
  for(int i = 1; i <= k; i++)
  {
    for(int j = i; j <= k; j++)
      if(i % 2 == 1)
      {
        if(j % 2 == 0)
          t++;
      }
       else if(i % 2 == 0)
      {
        if(j % 2 == 1)
          t++;
      }
  }
  cout << t;
  return 0;
}