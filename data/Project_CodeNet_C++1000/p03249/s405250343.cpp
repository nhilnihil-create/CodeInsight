#include <bits/stdc++.h>
using namespace std;
int sz[100005],par[100005];
pair<long long,int> a[100005];
map<long long,int> inv;
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i].first);
		a[i].second=i;
		sz[i]=1;
		inv[a[i].first]=i;
	}
	sort(a+1,a+n+1);
	for (int i=n;i>1;i--)
	{
		if (2*sz[a[i].second]>=n)
		{
			printf("-1");
			return 0;
		}
		int p=inv[a[i].first-n+2*sz[a[i].second]];
		if (!p)
		{
			printf("-1");
			return 0;
		}
		sz[p]+=sz[a[i].second];
		par[a[i].second]=p;
	}
	for (int i=2;i<=n;i++)
	a[1].first-=sz[a[i].second];
	if (a[1].first)
	printf("-1");
	else
	{
		for (int i=2;i<=n;i++)
		printf("%d %d\n",par[a[i].second],a[i].second);
	}
}