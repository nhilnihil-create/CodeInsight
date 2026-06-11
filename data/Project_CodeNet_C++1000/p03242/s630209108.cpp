#include<iostream>
using namespace std;
int main()
{
	int n,x[3];
	cin>>n;
	for(int i=0;i<3;i++)
	{
		x[i]=n%10;
		n/=10;
	}
	for(int i=2;i>=0;i--)
	cout<<10-x[i];
 } 