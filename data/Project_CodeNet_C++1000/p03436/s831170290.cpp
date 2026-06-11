#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int H,W;
char maze[60][60];
int d[60][60];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
void bfs(int sx,int sy){
    queue<pair<int,int>> que;
    rep(i,H){
        rep(j,W){
            d[i][j]=INF;
        }
    }
 
    que.push(make_pair(sx,sy)); // (0,0)ã‚¹ã‚¿ãƒ¼ãƒˆ
    d[sx][sy]=0;
    while(!que.empty()){
        pair<int,int> p=que.front();
        que.pop();
        for(int i=0;i<4;i++){
            int nx=p.first+dx[i];
            int ny=p.second+dy[i];
            if(0<=nx && nx<H && 0<=ny && ny<W && maze[nx][ny]!='#' && d[nx][ny]==INF){
                que.push(make_pair(nx,ny));
                d[nx][ny]=d[p.first][p.second]+1;
            }
        }
    }
}

int main(){
    cin>>H>>W;
    int c=0;
    rep(i,H){
        rep(j,W){
            cin>>maze[i][j];
            if(maze[i][j]=='.') c++;
        }
    }

    bfs(0,0);
    if(d[H-1][W-1]==INF){
        cout<<-1<<endl;
        return 0;
    }

    cout<<c-d[H-1][W-1]-1<<endl;
}