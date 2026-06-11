#include <bits/stdc++.h>
#define Maxn 1007
using namespace std;
int n,m;
char a[Maxn][Maxn];
bool vis[Maxn][Maxn];
int ans=0,dis[Maxn][Maxn];
int dx[4],dy[4];
pair<int,int> que[Maxn*Maxn*2];
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%s",a[i]+1);
    memset(vis,false,sizeof(vis));
    int lx=0,rx=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (a[i][j]=='#')
            {
                vis[i][j]=true;
                dis[i][j]=0;
                que[++rx]=make_pair(i,j);
            }
    dx[0]=0,dy[0]=1;
    dx[1]=0,dy[1]=-1;
    dx[2]=1,dy[2]=0;
    dx[3]=-1,dy[3]=0;
    while (lx<rx)
    {
        ++lx;
        int x=que[lx].first,y=que[lx].second;
        for (int i=0;i<4;i++)
        {
            int xx=x+dx[i];
            int yy=y+dy[i];
            if (xx>=1&&xx<=n&&yy>=1&&yy<=m&&(!vis[xx][yy]))
            {
                vis[xx][yy]=true;
                dis[xx][yy]=dis[x][y]+1;
                ans=max(ans,dis[xx][yy]);
                que[++rx]=make_pair(xx,yy);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}