#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5000005;
struct ab{int f,t;}t[N];
int a[N],size[N],id[N],hh[N],h,tot;
map<int,int>mp;
void make(int x,int y){t[++h].f=hh[x],t[h].t=y,hh[x]=h;}
int cmp(int x,int y){return a[x]>a[y];}
void dfs(int x,int y,int z)
{
	tot+=z;
	for(int i=hh[x];i;i=t[i].f)
	{
		int j=t[i].t;
		if(j==y) continue;
		dfs(j,x,z+1);
	}
}
signed main()
{
	int n;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",a+i),mp[a[i]]=i,size[i]=1,id[i]=i;
	sort(id+1,id+1+n,cmp);
	for(int i=1;i<n;i++)
	{
		int x=id[i],y=a[x]-(n-size[x])+size[x];
		if(!mp[y]||y>=a[x]) return printf("-1\n"),0;
		y=mp[y];
		make(x,y),make(y,x);
		size[y]+=size[x];
	}
	dfs(id[n],0,0);
	if(tot!=a[id[n]]) return printf("-1\n"),0;
	for(int i=1;i<=n;i++)
	{
		for(int j=hh[i];j;j=t[j].f)
		{
			if(t[j].t>i) printf("%lld %lld\n",i,t[j].t);
		}
	}
	return 0;
}