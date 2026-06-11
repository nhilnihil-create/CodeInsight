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
	int n,k;
	cin>>n>>k;int s=0;
	for(int i=max(1LL,k);i<=n;i++)
	{
		s+=(i-k)*(n/i);
		s+=max(n%i-(k-1), 0LL);
	}
	if(k==0)s-=n;
	cout<<s;
}