#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(long long i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,n-1,0)
#define RREPS(i,n) RFOR(i,n,1)
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

signed main(){
    int h,w;cin>>h>>w;
    char ma[h][w];
    queue<pair<int,int>>q;
    int depth[h][w];
    REP(i,h)REP(j,w){
        cin>>ma[i][j];
        depth[i][j]=INF;
        if(ma[i][j]=='#'){
            q.push({i,j});
            depth[i][j]=0;
        }
    }
    int ans=0;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        REP(i,4){
            int nx=x+dx[i];int ny = y +dy[i];
            if(nx>=0&&nx<h&&ny>=0&&ny<w&&depth[nx][ny]==INF){
                depth[nx][ny]=depth[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
    REP(i,h)REP(j,w)chmax(ans,depth[i][j]);
    cout<<ans<<endl;
}