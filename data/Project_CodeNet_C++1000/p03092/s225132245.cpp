#include<iostream>
#include<algorithm>
using namespace std;
int n;
long A,B,L[5555],R[5555];
int p[5555];
main()
{
	cin>>n>>A>>B;
	for(int i=0;i<n;i++)cin>>p[i];
	for(int i=0;i<n;i++)
	{
		long c=0;
		L[i]=9e18;
		for(int j=i;j--;)
		{
			if(p[j]>p[i])
			{
				c+=A;
			}
			else
			{
				L[i]=min(L[i],L[j]+c);
				c+=B;
			}
		}
		L[i]=min(L[i],c);
	}
	for(int i=n;i--;)
	{
		long c=0;
		R[i]=9e18;
		for(int j=i+1;j<n;j++)
		{
			if(p[j]>p[i])
			{
				R[i]=min(R[i],R[j]+c);
				c+=A;
			}
			else
			{
				c+=B;
			}
		}
		R[i]=min(R[i],c);
	}
	long ans=9e18;
	for(int i=0;i<n;i++)ans=min(ans,L[i]+R[i]);
	cout<<ans<<endl;
}