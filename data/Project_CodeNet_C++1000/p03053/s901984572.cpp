#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(ll i=0;i<n;i++)
using Graph = vector<vector<int>>;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

int main(){
    int h,w;cin>>h>>w;
    char g[h][w];
    queue<pair<int,int>> q;
    int dist[h][w];
    rep(i,h) rep(j,w) {
        cin>>g[i][j];
        if(g[i][j]=='#') {
            q.push(make_pair(i,j));
            dist[i][j]=0;
        }
        else dist[i][j]=-1;
    }


    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        rep(i,4){
            int ny=y+dy[i],nx=x+dx[i];
            if(ny>=0&&ny<h&&nx>=0&&nx<w&&g[ny][nx]=='.'&&dist[ny][nx]==-1){
                dist[ny][nx]=dist[y][x]+1;
                q.push(make_pair(ny,nx));
            }
        }
    }
    int ans=0;
    rep(i,h) rep(j,w) ans=max(ans,dist[i][j]);
    
    cout<<ans<<"\n";
}
