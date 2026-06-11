#include<bits/stdc++.h>
using namespace std;
int n,m,f;
int sum,ans;
int dx[8]={0,0,1,-1};
int dy[8]={1,-1,0,0};
int a[1010][1010];
char s[10000];
struct point
{
    int x;
    int y;
    int step;
}p,t;
void bfs(int x,int y)
{
    p.x=x;
    p.y=y;
    p.step=0;
    queue<point> q;
    q.push(p);
    while(!q.empty())
    {
        p=q.front();q.pop();
        if(p.x==n-1 && p.y==m-1)
        {
        	ans=sum-p.step-1;
        	printf("%d\n",ans);
        	f=1;
            exit(0);
        }
        for(int i=0;i<4;i++)
        {
            t.x=p.x+dx[i];
            t.y=p.y+dy[i];
            if(t.x>=0 && t.x<n && t.y>=0 && t.y<m && a[t.x][t.y]==0)
            {
                a[t.x][t.y]=1;
                t.step=p.step+1;
                q.push(t);
            }
        }
        
    }
}
int main()
{
    cin>>n>>m;
    for(int k=0; k<n; k++)
    {
        cin>>s;
        for (int j=0; j<m; j++)
        if (s[j]=='#') a[k][j]=1;
        else sum++;
    }
    a[0][0]=1;
    bfs(0,0);
    if (f==0) cout<<"-1"<<endl;
}