#include<bits/stdc++.h>

using namespace std;

int main(void)
{
  int a,b,x;

  cin>>a>>b>>x;

  for(int i=0;i<b;i++)
  {
    if(a==x)
    {
      cout<<"YES"<<endl;
      break;
    }
    else if(a<x)
    {
      a++;
    }
    else if(a>x)
    {
      cout<<"NO"<<endl;
      break;
    }
    
  }
      if(a<x)
    {
      cout<<"NO"<<endl;
    }
  
}
