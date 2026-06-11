#include <bits/stdc++.h>
using namespace std;
int main(void)
{
  int n,i,count=0,bit=0;
  cin >> n;
  int s[n];
  for(i=0;i<n;i++)
  {
    cin >> s[i];
  }
  while(bit == 0)
  {
    for ( i = 0; i < n; i++)
    {
      if(s[i] % 2 == 1)
      {
        bit = 1;
        break;
      }
    }
    if(bit == 1)
    {
      break;
    }
    for ( i = 0; i < n; i++)
    {
      s[i] /= 2;
    }
    count++;
  }
  cout << count;
  return 0;
}