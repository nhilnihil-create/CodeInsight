#include<iostream>
using namespace std;
int main (void)
{
  int x,i,j,k,n,ans;
  cin>>x;
  n=1;
  j=0;
  ans=0;
  if(x==1)
  {
    cout<<"1";
    return 0;
  }
  
  for(i=2;i<x;i++)
  {
    while(1)
    {
      if(n<=x)
      {
        n=n*i;
        j++;
      }
      else 
      {
        n=n/i;
      //  cout<<n<<endl;
        if(j>2&&n>ans)
        {
          ans=n;
        }
        n=1;
        j=0;
        break;
      }
    }
    
  }
  
  cout<<ans;

}