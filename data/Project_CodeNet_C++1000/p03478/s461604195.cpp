#include <bits/stdc++.h>
using namespace std;
int main(void)
{
  long long int n,a,b,sum=0,number,i,j,jj;
  cin >> n >> a >> b;
  for(i=0;i<=n;i++)
  {
    jj=i;
    number = 0;
    while (jj > 0)
    {
     number += jj % 10;
     jj /= 10;
    }
    if(a <= number && number <= b)
    {
      sum += i;
    }
  }
  cout << sum;
  return 0;
}