#include <stdio.h>
#include <string.h>
#include <queue>
#define MN 200000
#define MM 200000*2
int n,m,cnt;
int d[MN+5][2];
int hd[MN+5],to[MM+5],nxt[MM+5];
char s[MN+5]; bool vis[MN+5];
std::queue<int> q;
void add(int u,int v){
	static int rn=0;
	to[rn]=v,nxt[rn]=hd[u],hd[u]=rn++;
	d[v][s[u]-'A']++;
}
int main(){
	memset(hd,0xff,sizeof(hd));
	scanf("%d%d%s",&n,&m,&s[1]); cnt=n;
	for(int i=1;i<=m;i++){
		static int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		if(u!=v) add(v,u);
	}
	for(int i=1;i<=n;i++)
		if(d[i][0]==0||d[i][1]==0){
			q.push(i); vis[i]=true; cnt--;
		}
	while(!q.empty()){
		int u=q.front(); q.pop();
		for(int i=hd[u];~i;i=nxt[i]){
			if(vis[to[i]]) continue;
			if(--d[to[i]][s[u]-'A']==0){
				q.push(to[i]); vis[to[i]]=true; cnt--;
			}
		}
	}
	puts(cnt?"Yes":"No");
}