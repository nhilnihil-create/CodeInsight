#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

//read_code(drken)
int h,w;
vector<string> a;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    cin>>h>>w;
    a.resize(h);
    rep(i,h)cin>>a[i];
    vector<vector<int>>dist(h,vector<int>(w,-1));
    using pint = pair<int,int>;
    queue<pint>que;
    rep(i,h)rep(j,w)if(a[i][j]=='#'){
        dist[i][j]=0;
        que.push(pint(i,j));
    }
    
    while(!que.empty()){
        auto cur = que.front();
        que.pop();
        rep(i,4){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx<0 || nx>=h || ny<0 || ny>=w)continue;
            if(dist[nx][ny]==-1){
                dist[nx][ny]= dist[cur.first][cur.second] + 1;
                que.push(pint(nx, ny));
            }
        }
    }
    
    int ans = 0;
    rep(i,h)rep(j,w)ans=max(ans, dist[i][j]);
    cout<<ans<<endl;
	return 0;
}