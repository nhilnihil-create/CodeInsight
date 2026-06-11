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
	int n,x;cin>>n>>x;
	vector<int> a;
	int d;
	for(int i=0;i<n;i++)
	{
		cin>>d;
		a.push_back(abs(x-d));
	}
	int g=a[0];
	for(int i:a)g=__gcd(g,i);
	cout<<g<<"\n";
}
