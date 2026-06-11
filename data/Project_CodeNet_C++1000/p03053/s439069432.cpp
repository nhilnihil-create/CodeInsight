#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int H,W;
    cin >> H >> W;
    vector<string>A(H);
    vector<vector<int>>cnt(H,vector<int>(W,INF));
    queue<P> que;
    for(int i = 0; i < H; i++) {
        cin >> A[i];
        for(int j = 0; j < W; j++) {
            if(A[i][j] == '#') {
                que.push({i,j});
                cnt[i][j] = 0;
            }
        }
    }
    int ans = 0;
    while(!que.empty()) {
        P x = que.front();
        que.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x.first+dx[i];
            int ny = x.second+dy[i];
            if(nx >= 0 && nx < H && ny >= 0 && ny < W) {
                if(cnt[nx][ny] == INF) {
                    cnt[nx][ny] = cnt[x.first][x.second]+1;
                    ans = max(ans,cnt[nx][ny]);
                    que.push({nx,ny});
                }
            }
        }
    }
    cout << ans << endl;
}
