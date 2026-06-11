#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int n,m;
	cin>>n>>m;
	long int i,l[m],r[m],a,b;
	for( i=0;i<m;i++)
	{
		cin>>l[i]>>r[i];
	}
	a=l[0];
	b=r[0];
	for(i=0;i<m;i++)
	{
		if(a<=l[i])
		{
			a=l[i];
		}
		if(b>=r[i])
		{
			b=r[i];
		}
	}
	if(b>=a)
	{
		b=b-a+1;
	}
	else
	{
		b=0;
	}
	if(b<n)
	{
		cout<<b<<endl;
	}
	else
	{
		cout<<n<<endl;
	}
	
}