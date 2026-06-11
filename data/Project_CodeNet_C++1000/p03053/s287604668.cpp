#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<deque>
using namespace std;

int main() {
    typedef pair<int, int> pair;
    int H, W; cin >> H >> W;
    vector<string> maze(H);
    vector< vector<int> > dist(H, vector<int>(W, -1));
    for (int i = 0; i < H; i++) cin >> maze[i]; 

    deque<pair> q;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (maze[i][j] == '.') continue;
            q.push_back(make_pair(i, j));
            dist[i][j] = 0;
        }
    }

    while (!q.empty()) {
        auto curr = q.front();
        int h = curr.first;
        int w = curr.second;
        q.pop_front();
        if (h > 0 && dist[h - 1][w] == -1) {
            q.push_back(make_pair(h - 1, w));
            dist[h - 1][w] = dist[h][w] + 1;
        }
        if (h < H - 1 && dist[h + 1][w] == -1) {
            q.push_back(make_pair(h + 1, w));
            dist[h + 1][w] = dist[h][w] + 1;
        }
        if (w > 0 && dist[h][w - 1] == -1) {
            q.push_back(make_pair(h, w - 1));
            dist[h][w - 1] = dist[h][w] + 1;
        }
        if (w < W - 1 && dist[h][w + 1] == -1) {
            q.push_back(make_pair(h, w + 1));
            dist[h][w + 1] = dist[h][w] + 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            ans = max(dist[i][j], ans);
        }
    }
    cout << ans << endl;
}

