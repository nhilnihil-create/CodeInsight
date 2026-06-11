#include<iostream>
#define int long
using namespace std;
int n,a[1<<17];
main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	int l=2,r=2;
	for(int i=n-1;i>=0;i--)
	{
		if((l+a[i]-1)/a[i]*a[i]>r)
		{
			cout<<-1<<endl;
			return 0;
		}
		l=(l+a[i]-1)/a[i]*a[i];
		r=r/a[i]*a[i]+a[i]-1;
	}
	cout<<l<<" "<<r<<endl;
}
