#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const long long mo=50000007;
const int maxn=200010;

int n,m,id[maxn],fa[maxn];
long long d[maxn],siz[maxn],ans,js[maxn];
int tot,nex[maxn*2],las[maxn*2],tov[maxn*2];
int hs[mo+10];

void con(int x,int y)
{
	tot++;
	tov[tot]=y;
	nex[tot]=las[x];
	las[x]=tot;
}

void insert(long long x,int id)
{
	long long i=x%mo;
	while (hs[i]!=0)
	{
		i++;
		if (i==mo) i=0;
	}
	hs[i]=id;
}

long long find(long long x)
{
	long long i=x%mo;
	while (hs[i]!=0 && d[hs[i]]!=x)
	{
		i++;
		if (i==mo) i=0;
	}
	return hs[i];
}

void qsort(int l,int r)
{
	int i=l;int j=r;
	long long m=d[(i+j)/2];
	while (i<=j)
	{
		while (d[i]>m) i++;
		while (d[j]<m) j--;
		if (i<=j)
		{
			swap(d[i],d[j]);
			swap(id[i],id[j]);
			i++;j--;
		}
	}
	if (l<j) qsort(l,j);
	if (r>i) qsort(i,r);
}

void dfs(int x,int ff)
{
	js[x]=js[ff]+1;
	for (int i=las[x];i;i=nex[i])
	{
		if (tov[i]!=ff)
		{
			dfs(tov[i],x);
			ans+=js[x];
		}
	}
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&d[i]);
		id[i]=i;
		siz[i]=1;
	}
	qsort(1,n);
	for (int i=1;i<=n;i++)
	{
		insert(d[i],i);
	}
	for (int i=1;i<n;i++)
	{
		long long op=d[i]-(n-2*siz[i]);
		long long oq=find(op);
		if (oq==0 || oq==i)
		{
			printf("-1\n");
			return 0;
		}
		else
		{
			fa[i]=oq;
			siz[oq]+=siz[i];
			con(i,oq);con(oq,i);
		}
	}
	dfs(n,0);
	if (ans!=d[n])
	{
		printf("-1\n");
		return 0;
	}
	else
	{
		for (int i=1;i<n;i++)
		{
			printf("%d %d\n",id[i],id[fa[i]]);
		}
	}
}