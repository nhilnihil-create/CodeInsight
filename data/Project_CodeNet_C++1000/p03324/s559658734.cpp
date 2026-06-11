#include<iostream>
using namespace std;
int main(void)
{
  int d,i,j,k,l,n,ans;
  cin>>d>>n;
  ans=1;
  for(i=0;i<d;i++)
  {
    ans*=100;
  }
  if(n!=100){ans*=n;}
  else{ans=ans*(n+1);}
  cout<<ans;
  
  
}