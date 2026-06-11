#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

struct node
{
	int f,t;
} t[1000000];

long long a[1000000],size[1000000],id[1000000],hh[1000000],h,tot;
map<long long,int>mp;

void add(long long x,long long y)
{
	t[++h].f=hh[x];
	t[h].t=y;
	hh[x]=h;
}

int cmp(int x,int y)
{
	return a[x]>a[y];
}

void dfs(int x,int y,int z)
{
	tot+=z;
	for(int i=hh[x];i;i=t[i].f)
	{
		int j=t[i].t;
		if(j==y) 
			continue;
		dfs(j,x,z+1);
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%lld",a+i);
		mp[a[i]]=i;
		size[i]=1;
		id[i]=i;
	}
	sort(id+1,id+1+n,cmp);
	for(int i=1;i<n;i++)
	{
		long long x=id[i],y=a[x]-(n-size[x])+size[x];
		if(!mp[y]||y>=a[x]) 
		{
			printf("-1\n");
			return 0;
		}
		y=mp[y];
		add(x,y);
		add(y,x);
		size[y]+=size[x];
	}
	dfs(id[n],0,0);
	if(tot!=a[id[n]]) 
	{
		printf("-1\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=hh[i];j;j=t[j].f)
			if(t[j].t>i) 
				printf("%d %d\n",i,t[j].t);
	return 0;
}
