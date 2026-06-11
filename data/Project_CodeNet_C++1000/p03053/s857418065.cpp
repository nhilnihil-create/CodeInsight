#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
//#define MOD 1000000007
const int INF = 1LL<<30;

char fi[1010][1010];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int dist[1010][1010];

int main() {
    int h,w;
    cin>>h>>w;

    rep(i,h) rep(j,w) dist[i][j]=-1;
    queue<pair<int,int>> que;
    rep(i,h){
        rep(j,w){
            cin>>fi[i][j];
            if(fi[i][j]=='#'){
                que.push({i,j});
                dist[i][j]=0;
            } 
        }
    }

    


    while (!que.empty()) {
        auto v = que.front(); // キューから先頭頂点を取り出す
        que.pop();

        int x=v.first;
        int y=v.second;

        rep(i,4){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(dist[nx][ny]!=-1) continue;
            if(nx<0 || nx>=h || ny<0 || ny>=w) continue;
            dist[nx][ny]=dist[x][y]+1;
            que.push({nx,ny});


        }
    }

    int ans=0;
    rep(i,h){
        rep(j,w){
            ans=max(ans,dist[i][j]);
        }
    }

    cout<<ans<<endl;
}