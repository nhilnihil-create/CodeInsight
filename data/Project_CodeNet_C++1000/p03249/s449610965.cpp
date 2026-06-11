#include<bits/stdc++.h>
#define N 1000010
using namespace std;
struct S{
	long long w,dep;
	long long u,v,ne;
}a[N],e[N];
	long long n,sz[N],dy[N],fir[N],root,vis[N],sum,pan;
	bool bo=false;
void add(long long u,long long v){
	e[++sum].ne=fir[u];
	fir[u]=sum;
	e[sum].v=v;
	e[sum].u=u;
//	e[sum].w=1;
}
bool cmp(S x,S y){
	return x.w>y.w;
}
void check(long long x,long long dis){
//	if(bo)return;
	pan+=dis;
	vis[x]=1;
	for(long long i=fir[x];i;i=e[i].ne){
		long long to=e[i].v;
		if(!vis[to]){
			//if(vis[to])bo=true;
			check(to,dis+1);
		}
	}
}
void dfs(long long x,long long father){
	vis[x]=1;
	for(long long i=fir[x];i;i=e[i].ne){
		long long to=e[i].v;
		if(to!=father&&!vis[to]){
			printf("%lld %lld\n",x,to);
			dfs(to,x);
		}
	}
}
long long query(long long sum){
	long long l=1,r=n;
	while(l<r){
		long long mid=(l+r+1)>>1;
		if(a[mid].w>sum)l=mid;
		else if(a[mid].w<sum)r=mid-1;
		else {
			l=mid;
			return a[l].dep;
		}
	}
	return 0;
}
int main(){
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)scanf("%lld",&a[i].w),sz[i]=1,a[i].dep=i;
	sort(a+1,a+n+1,cmp);
	for(long long i=1;i<=n;i++){
		long long tmp=n-2*sz[a[i].dep];
		long long father=query(a[i].w-tmp);
		sz[father]+=sz[a[i].dep];
/*		if(!father){
			if(root){
				printf("-1\n");
				return 0;
			}
			root=a[i].dep;
		}
*/		if(i!=n){
			add(a[i].dep,father);
			add(father,a[i].dep);
		}
	}
	root=a[n].dep;
	check(root,0);
	if(bo){
		printf("-1\n");
		return 0;
	}
	for(long long i=1;i<=n;i++)if(!vis[i]){
		printf("-1\n");
		return 0;
	}
	if(pan!=a[n].w){
		printf("-1\n");
		return 0;
	}
	memset(vis,0,sizeof(vis));
	dfs(root,0);
}