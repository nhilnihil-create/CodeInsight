#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
 
const int INF = 100000000;
typedef pair<int ,int> P;
 
char maze[55][55];
int n,m;
int sx,sy;
int gx,gy;
 
int d[55][55];
 
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
 
int bfs()
{
    queue<P> que;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            d[i][j] = INF;
        }
    }
    que.push(P(sx,sy));
    d[sx][sy] = 0;
 
    while(que.size())
    {
        P p = que.front();
        que.pop();
        if(p.first == gx && p.second == gy)
            break;
        for(int i = 0;i<4;i++)
        {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if(nx>=0 && nx<=n && ny>=0 && ny<=m && maze[nx][ny] != '#' &&d [nx][ny] == INF)
            {
                que.push(P(nx,ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    return d[gx][gy];
}
int main()
{
    cin>>n>>m;
    int sum1 = 0;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            cin>>maze[i][j];
            if(maze[i][j]=='.')sum1++;
        }
    }
    sx=0;
    sy=0;
    gx=n-1;
    gy=m-1;
    int resourt = bfs();
    if(resourt==INF)cout<<"-1"<<endl;
    else cout<<sum1-resourt-1<<endl;
    return 0;
}