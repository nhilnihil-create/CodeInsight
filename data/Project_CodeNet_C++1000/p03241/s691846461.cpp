#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
const int N=2e5+5;
int n,m;
int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	cin>>m>>n;
	if(n%m==0)
		{cout<<n/m;return 0;}
	set<int> s;
	for(int i=1;i<=sqrt(n);i++)
	{
		if(n%i==0)
			{s.insert(i);s.insert(n/i);}

	}
	int ans=1;
	//for(auto i:s)cout<<i<<" ";
	for(auto i:s)
	{
		if((n/i)>=m)ans=i;
	}
	cout<<ans;


	
}