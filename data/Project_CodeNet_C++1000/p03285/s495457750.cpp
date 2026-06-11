#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,f;
  f=0;
  cin>>n;
  for(int i=0;i<=25;i++)
  {
    for(int j=0;j<=14;j++)
    {
      if(i*4+j*7==n)
      {
        f=1;
        break;
      }
    }
  }
  if(f==1)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
}