#include<iostream>
#include<queue>
using namespace std;
int n,m,giao=0,hp;
int xx[]={0,-1,0,0,1};
int yy[]={0,0,-1,1,0};
char c[110][110];
struct nd
{int x,y,time;};
int bfs(int x,int y)
{
    queue<nd>q;
    nd now,next;
    now.x=x;now.y=y;now.time=0;
    q.push(now);
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        if(now.x==n&&now.y==m)return now.time;
        for(int i=1;i<=4;i++)
        {
            next.x=now.x+xx[i];
            next.y=now.y+yy[i];
            next.time=now.time+1;
            if(next.x>0&&next.x<=n&&next.y>0&&next.y<=m&&c[next.x][next.y]=='.')
            {
                c[next.x][next.y]='#';
                q.push(next);
            }
        }
    }
    return -1;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>c[i][j];
			if(c[i][j]=='#')giao++;
		}
	c[1][1]='#';
	hp=bfs(1,1);
	if(hp!=-1)
	cout<<n*m-hp-giao-1;
	else cout<<-1;
}