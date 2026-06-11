#include<bits/stdc++.h>
#define ll long long
#define re register
#define ull unsigned ll
using namespace std;
inline ll read(){
	ll s=0,t=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*t;
}
#define f1 first
#define f2 second
#define mp make_pair
const int N=1e5+5;
int n,sz[N],f[N];ll Sum;
vector<int> G[N];
pair<ll,int> p[N];
void DFS(int x,ll d){Sum+=d;for(auto y:G[x])DFS(y,d+1);}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)sz[i]=1,p[i]=mp(read(),i);
	sort(p+1,p+n+1);
	for(int i=n;i>1;i--){
		int x=p[i].f2;
		ll v=p[i].f1+2*sz[x]-n;
		int j=lower_bound(p+1,p+i,mp(v,0))-p;
		if(j>n)return puts("-1"),0;
		G[f[x]=p[j].f2].push_back(x),sz[f[x]]+=sz[x];
	}DFS(p[1].f2,0);
	if(Sum^p[1].f1)return puts("-1"),0;
	for(int i=1;i<=n;i++)if(f[i])printf("%d %d\n",f[i],i);
	return 0;
}
