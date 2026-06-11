#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back

typedef long long LL;

const int N=100005;

int n,size[N],id[N],ans1[N],ans2[N];
LL tot,a[N];
std::map<LL,int> num;
std::vector<int> vec[N];

bool cmp(int x,int y)
{
	return a[x]>a[y];
}

void dfs(int x,int fa,int d)
{
	tot+=(LL)d;
	for (int i=0;i<vec[x].size();i++)
		if (vec[x][i]!=fa) dfs(vec[x][i],x,d+1);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]),num[a[i]]=i;
	for (int i=1;i<=n;i++) size[i]=1,id[i]=i;
	std::sort(id+1,id+n+1,cmp);
	for (int i=1;i<n;i++)
	{
		int x=id[i];LL w=a[x]-(n-size[x])+size[x];
		if (!num[w]||w>=a[x]) {puts("-1");return 0;}
		int y=num[w];
		ans1[i]=x;ans2[i]=y;
		vec[x].pb(y);vec[y].pb(x);
		size[y]+=size[x];
	}
	dfs(id[n],0,0);
	if (tot!=a[id[n]]) {puts("-1");return 0;}
	for (int i=1;i<n;i++) printf("%d %d\n",ans1[i],ans2[i]);
	return 0;
}