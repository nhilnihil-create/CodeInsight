#include<bits/stdc++.h>
using namespace std;
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
int n,el,head[maxn],to[maxn*2],nxt[maxn*2],dp[maxn],ans;
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
void dfs(int u,int f){
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f) continue;
		dfs(v,u);
		ans=max(ans,dp[u]+dp[v]+1);
		dp[u]=max(dp[u],dp[v]+1);
	}
}
int main(){
	n=read();
	FOR(i,1,n-1){
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	dfs(1,0);
	puts(ans%3==1?"Second":"First");
}