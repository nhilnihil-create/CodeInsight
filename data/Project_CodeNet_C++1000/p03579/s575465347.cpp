#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
const int maxn=200020;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,m,el,head[maxn],to[maxn],nxt[maxn],dep[maxn],cnt[2],tot;
ll ans;
bool ok;
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
void dfs(int u,int f){
	dep[u]=(dep[f]^1);
	tot++;
	cnt[dep[u]]++;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f) continue;
		if(~dep[v]){
			if(dep[v]!=(dep[u]^1)) ok=false;
		}
		else dfs(v,u);
	}
}
int main(){
	n=read();m=read();
	FOR(i,1,m){
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	MEM(dep,-1);dep[0]=0;
	FOR(i,1,n) if(dep[i]==-1){
		ok=true;
		cnt[0]=cnt[1]=tot=0;
		dfs(i,0);
		if(ok) ans+=1ll*cnt[0]*cnt[1];
		else ans+=1ll*tot*(tot-1)/2;
	}
	printf("%lld\n",ans-m);
}