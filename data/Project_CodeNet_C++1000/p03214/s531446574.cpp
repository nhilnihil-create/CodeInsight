#include<iostream>
#include<algorithm>
using namespace std;
int n,a[100],sum;
main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i],sum+=a[i];
	int ans=1e9,id;
	for(int i=0;i<n;i++)
	{
		if(ans>abs(sum-a[i]*n))
		{
			ans=abs(sum-a[i]*n);
			id=i;
		}
	}
	cout<<id<<endl;
}
