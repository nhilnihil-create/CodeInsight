#include<stdio.h>
#include<algorithm>
using namespace std;
struct node{
	int u;
	long long d;
	bool operator<(node b) const
	{
		return d<b.d;
	}
};
node nn[131072];
int size[131072],fa[131072],d[131072];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		nn[i].u=i;
		scanf("%lld",&nn[i].d);
		size[i]=1;
	}
	sort(nn+1,nn+n+1);
	for(int i=n;i>1;i--)
	{
		int l=1,r=i-1;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(nn[mid].d==nn[i].d+size[i]-(n-size[i]))
			{
				fa[i]=mid;
				break;
			}
			if(nn[mid].d>nn[i].d+size[i]-(n-size[i]))
			{
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
		if(!fa[i])
		{
			printf("-1\n");
			return 0;
		}
		size[fa[i]]+=size[i];
	}
	long long sd=0;
	for(int i=2;i<=n;i++)
	{
		d[i]=d[fa[i]]+1;
		sd+=d[i];
	}
	if(sd!=nn[1].d)
	{
		printf("-1\n");
		return 0;
	}
	for(int i=2;i<=n;i++)
	{
		printf("%d %d\n",nn[fa[i]].u,nn[i].u);
	}
	return 0;
}