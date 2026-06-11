#include<iostream>
using namespace std;
int main (void)
{
  int a,b,n,i,j,k,l,ans;
  n=0;ans=0;
  cin>>n>>a>>b;
  for(i=0;i<10;i++)
  {
    for(j=0;j<10;j++)
    {
      for(k=0;k<10;k++)
        for(l=0;l<10;l++)
        { if(1000*i+100*j+10*k+l>n){cout<<ans;return 0;}
          if(i+j+k+l<=b&&i+j+k+l>=a){ans+=1000*i+100*j+10*k+l;}
        }
    }
  }
  
  if(n==10000&&a==1&&b>=1)ans+=10000;
    
  cout<<ans;
  return 0; 
}