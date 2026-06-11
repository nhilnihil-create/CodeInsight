#include"bits/stdc++.h"
using namespace std;
int f[102];
int p[101][10];
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	int n,x;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<10;j++)
		{
			cin>>x;
			if(x)
			f[i]|=(1<<j);
		}
	}

	for(int i=0;i<n;i++)
		for(int j=0;j<11;j++)cin>>p[i][j];

	int ans=-1e9;
	for(int mask=1;mask<(1<<10);mask++)
	{
		int tmp=0;
		for(int i=0;i<n;i++)
		{
			x=mask&f[i];
			int ct=__builtin_popcount(x);
			tmp+=p[i][ct];
		}
		ans=max(ans,tmp);

	}
	cout<<ans;


}