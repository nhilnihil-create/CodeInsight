#include<iostream>
#include<vector>
using namespace std;
int n,k,a[1000];
long sum[1001];
vector<long>s;
main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)sum[i+1]=sum[i]+a[i];
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)s.push_back(sum[j]-sum[i]);
	}
	long ans=0;
	for(int i=50;i>=0;i--)
	{
		vector<long>tmp;
		for(int j=0;j<s.size();j++)
		{
			if(s[j]>>i&1)tmp.push_back(s[j]);
		}
		if(tmp.size()>=k)
		{
			s=tmp;
			ans|=1LL<<i;
		}
	}
	cout<<ans<<endl;
}
