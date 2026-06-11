#include <cstdio>
using namespace std;
const int N=200005;
int n,m,x,y,cnt,head[N],vis[N],deg[N][2],q[N],qtd,qtl;
char col[N];
struct edge{
  int to,nex;
}e[N*2];
void add(int x,int y){
  e[++cnt].to=y;e[cnt].nex=head[x];head[x]=cnt;
  e[++cnt].to=x;e[cnt].nex=head[y];head[y]=cnt;
}
int main(){
  scanf("%d%d",&n,&m);
  scanf("%s",col+1);
  for (int i=1;i<=m;i++) {
  scanf("%d%d",&x,&y),add(x,y);
  deg[x][col[y]=='B']++;deg[y][col[x]=='B']++;
  }
  for (int i=1;i<=n;i++)
    if (deg[i][0]==0||deg[i][1]==0) vis[q[qtl++]=i]=1;
  while (qtd!=qtl){
  	int x=q[qtd++];
  	for (int i=head[x];i;i=e[i].nex)
  	  if (!vis[e[i].to]){
  	  	 if (!--deg[e[i].to][col[x]=='B']){
  	  	 	  vis[e[i].to]=1;
  	  	 	  q[qtl++]=e[i].to;
			 }
		}
  }
  if (qtl==n) puts("No");
  else puts("Yes");
}