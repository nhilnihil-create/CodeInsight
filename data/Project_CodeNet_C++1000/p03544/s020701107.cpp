#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int n,i,x,a=2,b=1;
	cin>>n;

	if(n==0)
	{
		cout<<a<<endl;
		return 0;
		
	}
	if(n==1)
	{
		cout<<b<<endl;
		return 0;
	}	
	n=n-1;
	for(i=0;i<n;i++)
	{
	x=a+b;
	a=b;
	b=x;
	}
	cout<<x<<endl;
	
}