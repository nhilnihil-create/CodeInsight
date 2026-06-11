/**
 *    author:  FromDihPout
 *    created: 2020-08-16
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<pair<int,int>> ADJ = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    for (int i = 0; i < h; i++) {
        cin >> a[i];
    }
    
    int black = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            black += a[i][j] == '#';
        }
    }
    
    queue<pair<int,int>> q;
    q.push({0, 0});
    a[0][0] = '#';
    int dist = 1;
    bool reached = false;
    while (!q.empty()) {
        int len = q.size();
        for (int i = 0; i < len; i++) {
            pair<int,int> pos = q.front();
            q.pop();
            if (pos.first == h-1 && pos.second == w-1) {
                reached = true;
                break;
            }
            for (auto p : ADJ) {
                int x = pos.first + p.first, y = pos.second + p.second;
                if (x < 0 || x >= h || y < 0 || y >= w) continue;
                if (a[x][y] == '#') continue;
                q.push({x, y});
                a[x][y] = '#';
            }
        }
        if (reached) break;
        dist++;
    }
    
    int ans = -1;
    if (reached) {
        ans = (h * w) - dist - black;
    }
    cout << ans << '\n';
    return 0;
}