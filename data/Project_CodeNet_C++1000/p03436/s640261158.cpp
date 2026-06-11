#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int vis[1200][1200],dis[1200][1200];
int R,C;
int row[]= {1,0,-1,0,1,-1,1,-1};
int colm[]= {0,1,0,-1,1,-1,-1,1};
string maze[200];
void bfs(int input_x,int input_y)
{
    queue<pair<int,int> >q;
    vis[input_x][input_y] = 1;
    dis[input_x][input_y]   = 0;
    q.push(make_pair(input_x,input_y));
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++)
        {
            int u = x+row[i];
            int v = y+colm[i];
            if(0<=u && u<R && 0<=v && v<C)
            {
                if(vis[u][v]==0 && maze[u][v]=='.')
                {
                    vis[u][v]=1;
                    dis[u][v] = dis[x][y]+1;
                    q.push(make_pair(u,v));
                }
            }
        }
    }
    return ;
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    cin>>R>>C;
    for(int i=0; i<R; i++)
        cin>>maze[i];
    bfs(0,0);
    int cnt=0;
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            if(maze[i][j]=='.')
                cnt++;
        }
    }
    if(dis[R-1][C-1]==0){
        cout<<"-1"<<endl;
    }
    else{
        cout<<cnt-dis[R-1][C-1]-1<<endl;
    }

    return 0;
}
