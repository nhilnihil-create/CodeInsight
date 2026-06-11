#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
struct edge {
	int next,to,v;
} e[maxn];
int h[maxn],col[maxn],n,cnt;
void addedge(int x,int y,int z) {
	e[++cnt].next=h[x];
	e[cnt].to=y;
	e[cnt].v=z;
	h[x]=cnt;
}
void dfs(int u,int fa,int now) {
	//cout<<u<<' '<<fa<<' '<<now<<endl;
	col[u]=now;
	for(register int i=h[u]; i; i=e[i].next) {
		int j=e[i].to;
		if(j==fa) {
			continue;
		}
		dfs(j,u,e[i].v%2==1?(now^1):now);
	}
}
int main() {
	int x,y,z;
	scanf("%d",&n);
	for(register int i=1; i<n; i++) {
		scanf("%d%d%d",&x,&y,&z);
		addedge(x,y,z);
		addedge(y,x,z);
	}
	dfs(1,0,0);
	for(register int i=1; i<=n; i++) {
		printf("%d\n",col[i]);
	}
	return 0;
}