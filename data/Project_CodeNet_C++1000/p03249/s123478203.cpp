#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;

const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;

const int maxn=100111;
int n,pa[maxn],sz[maxn];
LL d[maxn];
pair<LL,int> vs[maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",d+i);
		vs[i]=mp(d[i],i);
		sz[i]=1;
	}
	sort(vs+1,vs+n+1);for(int i=1;i<=n;i++)d[i]=vs[i].ff;
	for(int i=n;i>=2;i--)
	{
		int dlt=(n-sz[i])-sz[i],id=lower_bound(d+1,d+n+1,d[i]-dlt)-d;
		if(id>=i||d[id]!=d[i]-dlt)
		{
			puts("-1");
			return 0;
		}
		pa[i]=id;
		sz[id]+=sz[i];
	}
	LL sum=0;
	for(int i=1;i<=n;i++)sum+=sz[i]-1;
	if(sum!=d[1])
	{
		puts("-1");
		return 0;
	}
	for(int i=2;i<=n;i++)printf("%d %d\n",vs[pa[i]].ss,vs[i].ss);
	return 0;
}