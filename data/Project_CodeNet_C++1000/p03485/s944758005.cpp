#include<iostream>
using namespace std;
int main()
{
  	int a,b,x;
  	cin>>a>>b;
  x=a+b;
  if(x%2==1)
    cout<<x/2+1;
  else
    cout<<x/2;
}