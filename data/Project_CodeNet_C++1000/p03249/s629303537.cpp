#include<cstdio>
#include<map>
#include<algorithm>
#define N 1000400
using namespace std;
int n,v2[N],fa[N];
long long v[N],sz[N],ds[N];
map<long long,int> tp;
bool cmp(int a,int b){return v[a]<v[b];}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&v[i]),tp[v[i]]=i,v2[i]=i,sz[i]=1;
	sort(v2+1,v2+n+1,cmp);
	for(int i=n;i>1;i--)
	{
		long long tp2=v[v2[i]]-n+sz[v2[i]]*2;
		if(!tp[tp2]){printf("-1\n");return 0;}
		int sb=tp[tp2];
		ds[sb]+=ds[v2[i]]+sz[v2[i]];
		sz[sb]+=sz[v2[i]];
		fa[v2[i]]=sb;
	}
	if(ds[v2[1]]!=v[v2[1]]){printf("-1\n");return 0;}
	for(int i=1;i<=n;i++)if(fa[i])printf("%d %d\n",i,fa[i]);
}//111222333