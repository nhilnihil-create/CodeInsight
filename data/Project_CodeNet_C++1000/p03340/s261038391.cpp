#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
int a[201000];
signed main()
{
	std::ios::sync_with_stdio(false);
	int n;cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	int now=0;
	ll ans=0;
	for(int l=1,r=1;r<=n;++r)
	{
		while(now&a[r])
		    now^=a[l++];
		now|=a[r];
		ans+=r-l+1;
	}
	cout<<ans<<'\n';
	return 0;
}