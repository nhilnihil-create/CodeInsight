#include  <bits/stdc++.h>
using namespace std;
int main()
{
	long long int i,n,t,a,s=0;	
	cin>>n>>t>>a;
	long double b[n],h[n];
	
	for(i=0;i<n;i++)
	{
		cin>>h[i];
		b[i]=t-(h[i]*0.006);
		
	}
	long double z=abs(b[0]-a);
	for(i=0;i<n;i++)
	{
		long double x;
		x=abs(b[i]-a);
		if(x<z)
		{
			z=x;
			s=i;
			
		}
	}
	cout<<s+1<<endl;
	
	
}