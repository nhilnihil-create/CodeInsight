#include <iostream>
using namespace std;

int main()
{
  	int a, b, p;
  	cin>>a>>b;
  	p=a*b;
  	if(p%2==0)
    	cout<<"Even";
  	if(p&2!=0)
      	cout<<"Odd";
  	return 0;
}