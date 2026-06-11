#include <cstdio>
const int maxn = 1e5+5;
int n,m,fa[maxn<<4],vis[maxn<<1];
inline int getfa(int x){return fa[x] == x ? x : fa[x] = getfa(fa[x]);}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=3*n;++i)fa[i] = i;
	int cnt = 0;
	for(int i=1,x,y,z;i<=m;++i){
		char c[2];
		scanf("%d %d %d",&x,&y,&z);
		if(z%2==0){
			int fx = getfa(x+n),fy = getfa(y+n);
			if(fx != fy)fa[fx] = fy;
			fx = getfa(x+n+n),fy = getfa(y+n+n);
			if(fx != fy)fa[fx] = fy;
		}
		else{
			int fx = getfa(x+n+n),fy = getfa(y+n);
			if(fx != fy)fa[fx] = fy;
			fx = getfa(x+n),fy = getfa(y+n+n);
			if(fx != fy)fa[fx] = fy;
		}
		int fx = getfa(x),fy = getfa(y);
		if(fx != fy)fa[fx] = fy;
	}
	for(int i=1;i<=n;++i){
		int fx = getfa(i);
		if(!vis[fx])vis[fx] = 1,++cnt;
	}
	printf("%d",cnt);
	return 0;
}