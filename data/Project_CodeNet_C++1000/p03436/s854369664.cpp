#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;

const ll INF=1LL<<60;
const int MOD=1e9+7;

int dx[]={1, 0, -1, 0};
int dy[]={0, 1, 0, -1};

int main(){
    int H, W; cin >> H >> W;
    vector<vector<char>> s(H, vector<char>(W, 0));
    int cnt=0;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> s[i][j];
            if(s[i][j] == '.') cnt++;
        }
    }
    queue<pii> que;
    vector<vi> dist(H, vi(W, 0));
    que.push({0,0});
    dist[0][0]=1;
    while(!que.empty()){
        int x, y;
        tie(x, y)=que.front();
        que.pop();
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 || nx>=H || ny<0 || ny>=W) continue;
            if(s[nx][ny] == '#' || dist[nx][ny] != 0) continue;
            dist[nx][ny]=dist[x][y]+1;
            que.push({nx, ny});
        }
    }
    if(dist[H-1][W-1] == 0) cout << -1 << endl;
    else cout << cnt-dist[H-1][W-1] << endl;
    return 0;
}
