#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
#define MAXN 100010
#define LL long long
using namespace std;
LL d[MAXN],dis[MAXN],siz[MAXN];
int n,cnt; 
map<LL,int> mp;
struct Edge{int u,v;}E[MAXN];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&d[i]);
	for(int i=1;i<=n;i++) mp[d[i]]=i;
	sort(d+1,d+n+1);
	for(int i=1;i<=n;i++) siz[i]=1;
	//d0=di+m-(n-m)=di+2m-n;
	for(int i=n;i>1;i--){ 
		int u=mp[d[i]];
	//	cout<<u<<' '<<d[i]<<endl;
		LL d0=d[i]+2*siz[u]-n;
		int v=mp[d0];
	//	cout<<"-----"<<v<<' '<<d0<<endl; 
		if(v){
			siz[v]+=siz[u];
			dis[v]+=(dis[u]+siz[u]);
			E[++cnt].u=min(u,v);
			E[cnt].v=max(u,v);
		}
		else{
			puts("-1");
			return 0;
		}
	}
	if(dis[mp[d[1]]]!=d[1]){
		puts("-1");
		return 0;
	}
	for(int i=1;i<=cnt;i++) printf("%d %d\n",E[i].u,E[i].v);
	return 0;
}