#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main (void)
{
  int i,a,b,k,d,gcd,c=0;
  cin>>a>>b>>k;
  while(1)
  {
    d=a%b;
    if(d==0){gcd=b;break;}
    a=b;
    b=d;
  }
  for(i=1;i<gcd;i++)
  {
    if(gcd%i==0)c++;
    if(c==k){break;}
  }
  cout<<gcd/i<<endl;
}