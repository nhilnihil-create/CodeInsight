#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int H,W;
    cin >> H >> W;
    vector<string>S(H);
    int cnt = 0;
    for(int i = 0; i < H; i++) {
        cin >> S[i];
        for(int j = 0; j < W; j++) {
            if(S[i][j] == '#') {
                cnt++;
            }
        }
    }
    queue<P> que;
    que.push({0,0});
    vector<vector<int>>count(H,vector<int>(W,INF));
    count[0][0] = 0;
    while(!que.empty()) {
        P X = que.front();
        que.pop();
        for(int i = 0; i < 4; i++) {
            int nx = X.first+dx[i];
            int ny = X.second+dy[i];
            if(nx >= 0 && nx < H && ny >= 0 && ny < W) {
                if(S[nx][ny] == '.') {
                    if(count[nx][ny] == INF) {
                        que.push({nx,ny});
                        count[nx][ny] = count[X.first][X.second]+1;
                    }
                }
            }
            if(nx == H-1 && ny == W-1) {
                cout << H*W-count[nx][ny]-cnt-1 << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
}
