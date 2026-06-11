#include <bits/stdc++.h>
using namespace std;

using P = pair<int,int>;
int bfs(int h,int w, vector<string> &s, int x, int y, int gx, int gy);
int main(void) {
    int H,W;
    int before = 0;
    int distance;
    cin >> H >> W;

    vector<string> s(H);
    for(int i=0;i<H;i++) {
        cin >> s[i];
        for(int j=0;j<s[i].size();j++) {
            if(s[i][j] == '#') {
                before++;
            }
        }
    }

    // 普通にBFSして距離を取る
    // H*W - 距離 - 事前の黒の数 が 答え
    
    distance = bfs(H,W,s,0,0,H-1,W-1);
    if(distance == -1) {
        cout << "-1\n";
    } else {
        cout << H * W - distance - before - 1 << endl;
    }

    return 0;
}

int bfs(int h,int w, vector<string> &s, int x, int y, int gx, int gy) {
    vector<int> dx = {-1,0,0,1};
    vector<int> dy = {0,-1,1,0};
    int cnt = 0;
    vector<vector<int>> dist(h,vector<int>(w,INT_MAX));

    queue<P> q;
    q.push(make_pair(x,y));
    dist[x][y] = 0;    
    while(!q.empty()) {
        P p = q.front();q.pop();
        if(p.first == gx && p.second == gy) return dist[gx][gy];

        for(int i=0;i<dx.size();i++) {
            x = p.first + dx[i];
            y = p.second + dy[i];
            if(x < 0 || y < 0 || x >= h || y >= w) continue;
            if(s[x][y] == '#') continue;
            if(dist[x][y] != INT_MAX) continue;
            dist[x][y] = dist[p.first][p.second] + 1;
            q.push(make_pair(x,y));
        }
    }
    return -1;
}
