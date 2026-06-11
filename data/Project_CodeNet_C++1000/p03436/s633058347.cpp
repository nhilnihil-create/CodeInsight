#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順
vector<string> M;
int H, W;

int main() {
    cin >> H >> W;

    int white = 0;
    rep(i,H) {
        string S; cin >> S;
        rep(j,W) {
            if (S[j] == '.') white++;
        }
        M.push_back(S);
    }

    queue<pair<int,int>> Q;
    vector<vector<int>> D(H, vector<int>(W, -1));
    Q.emplace(0,0);
    D[0][0] = 1;
    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        int dis = D[y][x];

        Q.pop();
        int dx[] = {1,0,-1, 0};
        int dy[] = {0,1, 0,-1};
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= W || ny >= H) continue;
            if (D[ny][nx] != -1) continue;
            if (M[ny][nx] == '#') continue;
            D[ny][nx] = dis + 1;
            Q.emplace(nx,ny);
        }
    }

    if (D[H-1][W-1] == -1) {
        cout << -1 << endl;
        return 0;
    }

    cout << white - D[H-1][W-1] << endl;
}
