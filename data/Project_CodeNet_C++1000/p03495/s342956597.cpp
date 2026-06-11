#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
const int N=2e5+3;
int f[N],a[N];
int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif

	int n,k;cin>>n>>k;
	for(int i=0;i<n;i++)
	{cin>>a[i];f[a[i]]++;}

	vector<int> val;
	for(int i=0;i<N;i++)
		if(f[i])val.push_back(f[i]);
	sort(val.begin(),val.end());
	int now=val.size();
	if(now<=k){puts("0");return 0;}
	int ans=0;
	for(int i=0;i<(now-k);i++)ans+=val[i];
	cout<<ans;
}
