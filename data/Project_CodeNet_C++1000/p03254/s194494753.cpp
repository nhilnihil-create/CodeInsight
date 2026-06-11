#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,x;
	cin>>n>>x;
	int i,a[n],b=0;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(i=0;i<n;i++)
	{
		x=x-a[i];
		if(x>=0)
		{	
			b++;
		}
		if(x<=0)
		{
			break;
		}
	}
	
		for(i=n-1;i>=0;i--)
		{
			if(x>0)
			{
			    x=x-a[i];
			    b--;
		    }
			if(x<=0)
			{
				break;
			}
					
		}	

	cout<<b<<endl;	
}