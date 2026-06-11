#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int d[1010][1010];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
    int H,W;
    cin>>H>>W;
    char maze[H][W];
    rep(i,H){
        rep(j,W){
            cin>>maze[i][j];
        }
    }

    queue<pair<int,int>> que;
    rep(i,H){
        rep(j,W){
            d[i][j]=INF;
            if(maze[i][j]=='#'){
                que.push(make_pair(i,j));
                d[i][j]=0;
            }
        }
    }
    
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
    int ans=0;
    rep(i,H){
        rep(j,W){
            ans=max(ans,d[i][j]);
        }
    }

    cout<<ans<<endl;
}