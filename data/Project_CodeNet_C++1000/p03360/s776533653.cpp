#include<bits/stdc++.h>
using namespace std;

int main()
{
  int a,b,c,k,x,y;
  cin>>a>>b>>c>>k;
  x=max(a,max(b,c));
  y=a+b+c-x;
  for(int i=0;i<k;i++)
  {
    x*=2;
  }
  cout<<y+x<<endl;
}