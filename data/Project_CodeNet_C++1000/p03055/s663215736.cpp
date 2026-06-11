#include<bits/stdc++.h>
#define ts cout<<"ok"<<endl
#define ll long long
#define hh puts("")
using namespace std;
int head[200005],n,cnt,d[200005];
struct Edge{
	int v,nx;
}e[400005];
inline int read(){
    int ret=0,ff=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') ff=-ff;ch=getchar();}
    while(isdigit(ch)){ret=(ret<<3)+(ret<<1)+(ch^48);ch=getchar();}
    return ret*ff;
}
inline void add(int x,int y){
	e[++cnt].v=y;
	e[cnt].nx=head[x];
	head[x]=cnt;
}
void dfs(int now,int fa){
	for(int i=head[now];i;i=e[i].nx){
		int v=e[i].v;
		if(v==fa) continue;
		d[v]=d[now]+1;
		dfs(v,now);
	}
}
signed main(){
	n=read();
	for(int i=1;i<n;i++){
		int x=read(),y=read();
		add(x,y);
		add(y,x);
	}
	d[1]=1;
	dfs(1,0);
	int mx=0;
	for(int i=1;i<=n;i++)
		if(d[i]>d[mx])
			mx=i;
	d[mx]=1;
	dfs(mx,0);
	mx=0;
	for(int i=1;i<=n;i++)
		if(d[i]>mx)
			mx=d[i];
	puts(mx%3==2?"Second":"First");
    return 0;
}