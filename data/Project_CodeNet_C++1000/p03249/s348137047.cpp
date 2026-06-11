#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct pt
{
	ll val;
	int id;
	pt(ll val=0,int id=0):val(val),id(id){}
	bool operator<(const pt x) const
	{
		return val>x.val;
	}
}a[100005];
int n,e[100005][2],sz[100005];
ll f[100005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i].val),a[i].id=i;
	for(int i=1;i<=n;i++)
		sz[i]=1;
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
	{
		int u=a[i].id,v;
		int nw=lower_bound(a+1,a+n+1,pt(a[i].val-n+2*sz[u]))-a;
		if(a[nw].val!=a[i].val-n+2*sz[u])
		{
			printf("-1");
			return 0;
		}
		v=a[nw].id;
		e[i][0]=u,e[i][1]=v;
		sz[v]+=sz[u],f[v]+=f[u]+sz[u];
	}
	if(f[a[n].id]!=a[n].val)
	{
		printf("-1");
		return 0;
	}
	for(int i=1;i<n;i++)
		printf("%d %d\n",e[i][0],e[i][1]);
	return 0;
}