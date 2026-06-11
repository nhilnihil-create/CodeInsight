#include<iostream>

using namespace std;

int main(void)
{
  int a,b,c;
  cin>>a>>b>>c;
  
  if((a!=b)&&(b==c)){cout<<a<<endl;}
  else if((b!=c)&&(c==a)){cout<<b<<endl;}
  else if((c!=a)&&(a==b)){cout<<c<<endl;}
  
  return 0;
}