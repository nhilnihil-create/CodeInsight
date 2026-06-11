#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define MN 200005
using namespace std;
int n,m,num,que[MN<<4],head[MN<<4],rd[MN<<4];char s[MN];
struct edge{int to,next;}g[MN<<4];
void ins(int u,int v){g[++num].next=head[u];head[u]=num;g[num].to=v;}
int main(){
	scanf("%d%d%s",&n,&m,s+1);int x,y;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		if(x==y)ins(x+n,x+2*n),ins(x+3*n,x);
		else if(s[x]==s[y])ins(x+n,y),ins(x+n,y+2*n),ins(x+3*n,y),ins(x+3*n,y+2*n),ins(y+n,x),ins(y+n,x+2*n),ins(y+3*n,x),ins(y+3*n,x+2*n);
		else ins(x,y+n),ins(x,y+3*n),ins(x+2*n,y+n),ins(x+2*n,y+3*n),ins(y,x+n),ins(y,x+3*n),ins(y+2*n,x+n),ins(y+2*n,x+3*n);
	}
	for(int i=1;i<=4*n;i++)for(int j=head[i];j;j=g[j].next)rd[g[j].to]++;
	int h=1,t=0;for(int i=1;i<=4*n;i++)if(rd[i]==0)que[++t]=i;
	while(h<=t){
		
		int tmp=que[h++];
		for(int i=head[tmp];i;i=g[i].next)if(!(--rd[g[i].to]))que[++t]=g[i].to;
	}if(t==n*4)puts("No");else puts("Yes");
}
