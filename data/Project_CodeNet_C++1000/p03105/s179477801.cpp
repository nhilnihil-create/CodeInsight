#include<bits/stdc++.h>
using namespace std;
int main() 
{
  int A,B,C,d;
  cin>>A>>B>>C;
  d=B/A;
  if (d>=C)
  {
     cout<<C<<endl;
  }
  else if (d<C)
  {
      cout<<d<<endl;
  }
  
  return 0;
}