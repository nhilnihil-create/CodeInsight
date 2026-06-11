#include<bits/stdc++.h>
using namespace std;
int a[202020],n;
long long s[202020];
long long cal(int x,int y,int z)
{
	if(x<=0 || x>=y || y>=z || z>=n)
	{
		return 1e18+10;
	}
	vector<long long>v;
	v.push_back(s[x]-s[0]);
	v.push_back(s[y]-s[x]);
	v.push_back(s[z]-s[y]);
	v.push_back(s[n]-s[z]);
	sort(v.begin(),v.end());
	return v[3]-v[0];
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		s[i+1]=s[i]+a[i];
	}
	long long ans=1e18+10;
	for(int i=2;i<n-1;i++)
	{
		int x=upper_bound(s,s+n+1,s[i]/2)-s,y=upper_bound(s,s+n+1,s[i]+(s[n]-s[i])/2)-s;
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<2;k++)
			{
				ans=min(ans,cal(x-j,i,y-k));
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}