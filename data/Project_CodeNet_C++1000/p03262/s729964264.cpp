#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;


int main (void)
{
  int n,x,i,a,d,b,GCD;
  cin>>n>>x;
  for(i=0;i<n;i++)
  {
    cin>>a;
    if(i==0){GCD=abs(a-x);}
    else
    {
      b=abs(a-x);
      d=b%GCD;
      while(d!=0)
      {
        b=GCD;
        GCD=d;
        d=b%GCD;
      }
    }
  }
  cout<<GCD<<endl;
}