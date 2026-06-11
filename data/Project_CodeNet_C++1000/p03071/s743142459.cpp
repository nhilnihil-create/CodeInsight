#include<bits/stdc++.h>
using namespace std;
int main() 
{

  int a,b;
  cin>>a>>b;
  if (a>b)
  {
      cout<<a+(a-1)<<endl;
  }
  else if (a==b)
  {
      cout<<2*a<<endl;
  }
  else
  {
      cout<<b+(b-1)<<endl;
  }

  return 0;
}