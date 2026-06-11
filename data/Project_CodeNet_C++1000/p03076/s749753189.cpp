#include <bits/stdc++.h>
using namespace std;
int main()
{
	int i,a[5],x,s=0;
	for(i=0;i<5;i++)
	{
		cin>>a[i];		
	}
	
	for(i=1;i<5;i++)
	{
		x=a[i]%10;
		if(x==0)
		{
			x=10;
		}
		
		if(x>a[i-1]%10)
		{
			int s;
			s=a[i];
			a[i]=a[i-1];
			a[i-1]=s;
			
		}
		
		
	}
	for(i=0;i<5;i++)
	{
		
		if(a[i]%10!=0 && i!=4)
		{
			a[i]=a[i]+(10-a[i]%10);
		}
		s=s+a[i];
	}
	cout<<s<<endl;
	
	
	
}