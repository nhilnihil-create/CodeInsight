#include<bits/stdc++.h>
using namespace std;
#define REP(i,st,ed) for(register int i=st,i##end=ed;i<=i##end;++i)
#define DREP(i,st,ed) for(register int i=st,i##end=ed;i>=i##end;--i)
typedef long long ll;
template<typename T>inline bool chkmin(T &x,T y){return (y<x)?(x=y,1):0;}
template<typename T>inline bool chkmax(T &x,T y){return (y>x)?(x=y,1):0;}
inline int read(){
    int x;
    char c;
    int f=1;
    while((c=getchar())!='-' && (c>'9' || c<'0'));
    if(c=='-') f=-1,c=getchar();
    x=c^'0';
    while((c=getchar())>='0' && c<='9') x=(x<<1)+(x<<3)+(c^'0');
    return x*f;
}
inline ll readll(){
    ll x;
    char c;
    int f=1;
    while((c=getchar())!='-' && (c>'9' || c<'0'));
    if(c=='-') f=-1,c=getchar();
    x=c^'0';
    while((c=getchar())>='0' && c<='9') x=(x<<1ll)+(x<<3ll)+(c^'0');
    return x*f;
}
const int maxn=2e5+10;
char s[maxn];
int vis[2][maxn],p[maxn];
int l[maxn],r[maxn],Begin[maxn],Next[maxn<<1],to[maxn<<1],w[maxn<<1],e;
inline void add_edge(int x,int y,int z){
	to[++e]=y;
	Next[e]=Begin[x];
	Begin[x]=e;
	w[e]=z;
}
queue<int> q;
int main(){
	int n=read(),m=read();
	scanf("%s",s+1);
	REP(i,1,m) l[i]=read(),r[i]=read();
	REP(i,1,m){
		vis[s[l[i]]-'A'][r[i]]++,vis[s[r[i]]-'A'][l[i]]++;
		add_edge(l[i],r[i],s[l[i]]-'A'),add_edge(r[i],l[i],s[r[i]]-'A');
	}
	int cnt=n;
	REP(i,1,n){
		if(vis[0][i]>0 && vis[1][i]>0) continue;
		q.push(i),p[i]=1;
	}
	while(!q.empty()){
		int u=q.front();q.pop(),--cnt;
		for(int i=Begin[u];i;i=Next[i]) if(!p[to[i]]){
			--vis[w[i]][to[i]];
			if(!vis[w[i]][to[i]]) q.push(to[i]),p[to[i]]=1;
		}
	}
	printf("%s\n",cnt?"Yes":"No");
    return 0;
}