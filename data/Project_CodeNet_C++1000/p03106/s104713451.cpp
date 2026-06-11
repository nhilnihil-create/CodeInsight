#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
  int a,b,k;
  cin >> a >> b >> k;
  int common_divisor[101];

  int n=min(a,b);
  int num[101]={0};

  for(int i=1; i<=n; i++)
  {
    if( a%i==0 && b%i==0 )
      num[i]=1;
  }

  int j=0;
  for(int i=1; i<=n; i++)
  {
    if(num[i]==1)
    {   
      common_divisor[j] = i;
      j++;
    }   
  }
    
  cout << common_divisor[j-k] << endl;
  return 0;
}
