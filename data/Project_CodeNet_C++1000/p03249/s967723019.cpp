#include<bits/stdc++.h>
using namespace std;

#define fatherdis fd

long long ans=0,n,father[100010],size[100010],first[100010],nxt[200020],u[200020],v[200020],tot=0,tmp,fatherdis,pos,judge=0,j,root,depth[100010]={0};

struct csx
{
	long long num,dis;
}p[100010];

bool cmp(const csx a,const csx b)
{
	if (a.dis<b.dis) return true;
	else return false;
}

void add(long long from,long long to)
{
	tot++;
	nxt[tot]=first[from];
	first[from]=tot;
	u[tot]=from;
	v[tot]=to;
	return;
}

void dfs(long long point)
{
	long long k=first[point];
	while (k!=-1)
	{
		long long to=v[k];
		if (father[point]!=to)
		{
		    depth[to]=depth[point]+1;
			dfs(to);
		}
		k=nxt[k];
	}
	ans+=depth[point];
	return;
}

int main()
{
	memset(first,-1,sizeof(first));
	scanf("%lld",&n);
	for (int i=1;i<=n;i++) 
	{
		scanf("%lld",&tmp);
		size[i]=1;
	    p[i].num=i;
	    p[i].dis=tmp;
	}
	sort(p+1,p+n+1,cmp);
	root=p[1].num;
	for (int i=n;i>1;i--)
	{
		fd=p[i].dis-(n-2*size[p[i].num]);
		j=i-1;
		while (j>0&&p[j].dis!=fd) j--;
		if (!j) 
		{
			judge=1;
			break;
		}
		father[p[i].num]=p[j].num;
		size[p[j].num]+=size[p[i].num];
		add(p[j].num,p[i].num);
		add(p[i].num,p[j].num);
	}
	dfs(root);
	if (judge||ans!=p[1].dis) printf("-1");
	else for (int i=1;i<=tot/2;i++) printf("%lld %lld\n",u[i*2],v[i*2]);
	return 0;
}