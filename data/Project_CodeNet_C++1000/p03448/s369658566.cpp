#include <bits/stdc++.h>
using namespace std;
int main(void)
{
  int a,b,c,x,i,j,k,count=0,sum;
  cin >> a >> b >> c >> x;
  for(i=0;i<=a;i++)
  {
    for ( j = 0; j <= b; j++)
    {
      for ( k = 0; k <= c; k++)
      {
        sum = 500*i+100*j+50*k;
        if(sum == x)
        {
          count++;
        }
      }
    }
  }
  cout << count;
  return 0;
}