#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long ll;
const int N=200200;
int n,u,o[N],sz[N],fa[N];
ll t,a[N],su[N];
map<ll,int>h;
bool cmp(int x,int y){return a[x]>a[y];}
int main(){
	scanf("%d",&n);
	FOR(i,1,n) scanf("%lld",&a[i]),h[a[i]]=o[i]=i,sz[i]=1;
	sort(o+1,o+n+1,cmp);
	FOR(i,1,n-1){
		u=o[i];t=a[u]+2*sz[u]-n;
		if(!h.count(t) || h[t]==u || fa[h[t]]) return puts("-1"),0;
		sz[fa[u]=h[t]]+=sz[u];
		su[fa[u]]+=su[u]+sz[u];
	}
	if(su[o[n]]!=a[o[n]]) return puts("-1"),0;
	FOR(i,1,n)if(fa[i]) cout<<i<<' '<<fa[i]<<'\n';
}