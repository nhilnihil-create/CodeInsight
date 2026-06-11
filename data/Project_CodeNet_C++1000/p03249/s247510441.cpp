#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
const int N=1e5+5;
int n,p[N],fa[N],sz[N],dep[N];long long d[N];
map<long long,int>Map;
bool cmp(int x,int y){
	return d[x]>d[y];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%lld",&d[i]);
		Map[d[i]]=i;p[i]=i;sz[i]=1;
	}
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<n;++i){
		int x=p[i];
		fa[x]=Map[d[x]-n+sz[x]+sz[x]];
		if(!fa[x]||fa[x]==x)return puts("-1"),0;
		sz[fa[x]]+=sz[x];
	}
	long long sum=0;
	for(int i=n-1;i;--i)dep[p[i]]=dep[fa[p[i]]]+1,sum+=dep[p[i]];
	if(sum!=d[p[n]])return puts("-1"),0;
	for(int i=1;i<n;++i)printf("%d %d\n",p[i],fa[p[i]]);
	return 0;
}
