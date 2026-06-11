#include <bits/stdc++.h>
using namespace std;
int main()
{
  int N , c1 , c2 = 0;
  cin >> N;
  for(int i = 1 ; i <= N ; i++)
  {
    if(i % 2 == 1)
    {
      c1 = 0;
      for(int j = 1 ; j <= i ; j++)
      {
        if(i % j == 0)
        {
          c1++;
        }
      }
      if(c1 == 8)
      {
        c2++;
      }
    }
  }
  cout << c2 << endl;
}