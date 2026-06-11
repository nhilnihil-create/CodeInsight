#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, m, n) for (int i = m; i < n; ++i)
#define FORR(i, m, n) for (int i = m; i >= n; --i)
#define ALL(v) (v).begin(),(v).end()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=(1<<30)-1;
const int mod=1e9+7;
int dx[8]={1,0,-1,0,-1,-1,1,1};
int dy[8]={0,1,0,-1,-1,1,-1,1};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h,w;cin >> h >> w;
    char a[h][w];
    queue<pair<int,int>> q;
    vector<vector<int>> d(h,vector<int>(w,inf));
    REP(i,h){
        REP(j,w){
            cin >> a[i][j];
            if(a[i][j]=='#'){
                q.push({i,j});
                d[i][j]=0;
            }
        }
    }
    while(!q.empty()){
        int u=q.front().first,v=q.front().second;
        q.pop();
        REP(i,4){
            int x=u+dx[i],y=v+dy[i];
            if(x>=0&&x<h&&y>=0&&y<w){
                if(chmin(d[x][y],d[u][v]+1)){
                    q.push({x,y});
                }
            }
        }
    }
    int ans=0;
    REP(i,h) REP(j,w) chmax(ans,d[i][j]);
    cout << ans << endl;
}