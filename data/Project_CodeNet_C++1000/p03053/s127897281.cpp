#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(long long i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,N-1,0)
#define RREPS(i,n) RFOR(i,N,1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
const int INF=1e18;
const int MOD=1e9+7;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
typedef pair<int,int> P;

signed main(){
    int H,W;cin>>H>>W;
    char maze[H][W];
    int depth[H][W];
    REP(i,H)REP(j,W)depth[i][j]=INF;
    queue<P> q;
    REP(i,H)REP(j,W){
        cin>>maze[i][j];
        if(maze[i][j]=='#')q.push({i,j});
    }
    int ans=0;
    while(q.size()){
        P p=q.front();q.pop();
        int nx=p.first,ny=p.second;
        if(depth[nx][ny]==INF)depth[nx][ny]=0;
        REP(i,4){
            int x=nx+dx[i];
            int y=ny+dy[i];
            if(x>=0&&x<H&&y>=0&&y<W&&depth[x][y]==INF&&maze[x][y]=='.'){
                depth[x][y]=depth[nx][ny]+1;
                q.push({x,y});
            }
        }
    }
    REP(i,H)REP(j,W)chmax(ans,depth[i][j]);
    cout<<ans<<endl;
}