#include<iostream>
#include<algorithm>
using namespace std;
int n;
long X,x[2<<17],s[4<<17];
long ans=9e18;
main()
{
	cin>>n>>X;
	for(int i=0;i<n;i++)cin>>x[i];
	for(int i=0;i<n;i++)s[i+1]=s[i]+x[n-i-1];
	for(int i=n;i<n+n;i++)s[i+1]=s[i];
	for(int k=1;k<=n;k++)
	{
		long now=(n+k)*X;
		for(int i=0;i<n;i+=k)
		{
			now+=(s[i+k]-s[i])*(i/k==0?5:i/k*2+3);
		}
		ans=min(ans,now<0?ans:now);
	}
	cout<<ans<<endl;
}