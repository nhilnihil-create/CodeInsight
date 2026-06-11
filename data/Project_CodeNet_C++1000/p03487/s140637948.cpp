#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif

	int n;
	cin>>n;
	map<int,int> f;
	int x;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		f[x]++;
	}

	int ans=0;

	for(auto i:f)
	{
		x=i.first;

		if(f[x]>=x)ans+=f[x]-x;
		else ans+=f[x];
	}

	cout<<ans;
	




	
}