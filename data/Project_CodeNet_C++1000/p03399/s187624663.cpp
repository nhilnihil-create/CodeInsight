#include<iostream>
using namespace std;
int main()
{
  	int a,b,c,d;
  	cin>>a>>b>>c>>d;
  if(a>=b)
    if(c>=d)
      cout<<b+d;
  	else
      cout<<b+c;
  else
    if(c>=d)
      cout<<a+d;
  	else
      cout<<a+c;
}