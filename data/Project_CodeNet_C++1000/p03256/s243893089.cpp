#include<bits/stdc++.h>
#define Rint register int
#define mem(a,b) memset(a,(b),sizeof(a))
#define File(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define For(i,j,k) for(Rint i=(j);i<=(k);i++)
#define Fordown(i,j,k) for(Rint i=(j);i>=(k);i--)

using namespace std;
typedef long long LL;

template<typename T>inline void read(T &x){
	x=0;T w=1,ch=getchar();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	x=x*w;
}

const int N=2e5+10;
int n,m;
int e,beg[N],nex[N<<1],to[N<<1];
bool s[N],vis[N<<1],Vis[N<<1],w[N<<1];
char ch;

inline void add(int x,int y,int z){
	to[++e]=y;
	nex[e]=beg[x];
	beg[x]=e;
	w[e]=z;
}
inline void dfs(int id,int x){
	for(Rint i=beg[x];i;i=nex[i])if(w[i]!=w[id]){
		if(!vis[i]){
			Vis[i]=vis[i]=1;
			dfs(i,to[i]);
			vis[i]=0;
		}
		else printf("Yes\n"),exit(0);
	}
}

int main(){
	read(n);read(m);
	For(i,1,n){
		do ch=getchar();while(ch!='A'&&ch!='B');
		s[i]=(ch=='A'?1:0);
	}
	For(i,1,m){
		int x,y;read(x);read(y);
		add(x,y,s[x]==s[y]);add(y,x,s[x]==s[y]);
	}
	For(i,1,m<<1)if(!Vis[i])dfs(i,to[i]);
	printf("No\n");
	return 0;
}