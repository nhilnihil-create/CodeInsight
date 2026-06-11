#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int i,j,a,b,k;
	cin>>a>>b>>k;
	if(a>b)
	{
		cout<<0<<endl;
		return 0;
	}
	for(i=1;i<=k && a<=b;i++)
	{
	
		cout<<a<<endl;
		a=a+1;
		
	}
	a--;
	for(i=b-k+1;i<=b && i>=0;i++)
	{
		if(i>a)
		{
			cout<<i<<endl;
		}
	}
	
	
	
		
} 