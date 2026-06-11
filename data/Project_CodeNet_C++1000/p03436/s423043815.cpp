#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#define N 55
using namespace std;
char Fuck[N][N];
int n,m,cnt;
int vis[N][N];
struct node
{
	int x, y;
}q[N*N];
bool nmsl[N][N];
const int r[]={1,-1,0,0};
const int w[]={0,0,1,-1};
inline void bfs(int sx, int sy)
{
	int hd,tl,dx,dy,fx,fy;
	hd=tl=1;
	q[1].x=sx;
	q[1].y=sy;
	while(hd<=tl)
	{
		fx=q[hd].x;
		fy=q[hd].y;
		hd++;
		for(int i=0;i<4;++i)
		{
			dx=fx+r[i];
			dy=fy+w[i];
			if(dx<1||dy<1||dx>n||dy>m||Fuck[dx][dy]=='#'||nmsl[dx][dy]==1) 
			continue;
			nmsl[dx][dy]=1;
			tl++;
			q[tl].x=dx;
			q[tl].y=dy;
			vis[dx][dy]=vis[fx][fy]+1;
			if(dx==n&&dy==m) 
			return ;
		}
	}
}
int main()
{
	cin>>n>>m;
	memset(vis,127/3,sizeof vis );
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			cin>>Fuck[i][j];
			if(Fuck[i][j]=='#') 
			cnt++;
		}
	}
	vis[1][1]=1;
	nmsl[1][1]=1;
	bfs(1,1);
	int ans=n*m-cnt-vis[n][m];
	if(ans<0) 
	puts("-1");
	else 
	printf("%d",ans);
}