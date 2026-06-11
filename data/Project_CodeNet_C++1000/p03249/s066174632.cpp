#include<iostream>
#include<algorithm>
using namespace std;

int n,sz[1000000],par[1000000];
long long d[1000000],chdst[1000000];
pair<long long,int>id[1000000];

bool solve()
{
	for(int i=0;i<n;i++)
		id[i]=make_pair(d[i],i);
	sort(id,id+n);
	for(int i=0;i<n;i++)
	{
		sz[i]=1,par[i]=-2;
		chdst[i]=0;
	}
	for(int i=n-1;i >= 1;--i)
	{
		int at=id[i].second;
		long long want=d[at]-n+2 * sz[at];
		int idx=lower_bound(id,id+n,make_pair(want,-1))-id;
		if(idx >= i || id[idx].first!=want)
			return false;
		par[at]=id[idx].second;
		sz[par[at]] += sz[at];
		chdst[par[at]] += chdst[at]+sz[at];
	}
	int root=id[0].second;
	par[root]=-1;
	return chdst[root]==d[root];
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%lld",&d[i]);
	if(!solve())
	{
		printf("-1");
		return 0;
	}
	for(int i=0;i<n;i++)
		if(par[i]!=-1)
			printf("%d %d\n",i+1,par[i]+1);
	return 0;
}