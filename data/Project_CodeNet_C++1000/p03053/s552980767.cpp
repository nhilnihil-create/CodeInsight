#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using P = pair<int,int>;
using graph = vector<vector<char>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int H,W;
    cin>>H>>W;
    graph g(H,vector<char>(W));
    queue<P> bfs;
    vector<vector<int>> d(H,vector<int>(W,-1));
    rep(i,H){
        rep(j,W) {
            cin>>g[i][j];
            if(g[i][j]=='#'){
                bfs.push(make_pair(i,j));
                d[i][j]=0;
            }
        }
    }
    while(!bfs.empty()){
        P p = bfs.front();
        bfs.pop();
        int x = p.first;
        int y = p.second;
        rep(i,4){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0||nx>=H||ny<0||ny>=W) continue;
            if(d[nx][ny]!=-1) continue;
            d[nx][ny] = d[x][y]+1;
            bfs.push(make_pair(nx,ny));
        }
    }
    int ans = 0;
    rep(i,H){
        rep(j,W) chmax(ans,d[i][j]);
    }
    cout<<ans<<endl;
}