#include <bits/stdc++.h>
using namespace std;
const vector<int> v = {0, -1, 0, 1};
const vector<int> h = {-1, 0, 1, 0};

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> s(H+1, vector<char>(W+1));
    queue<vector<int>> que;
    vector<vector<int>> dist(H+1, vector<int>(W+1, -1));

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> s.at(i).at(j);
            if (s.at(i).at(j) == '#') {
                que.push({i, j});
                dist.at(i).at(j) = 0;
            }
            
        } 
    }
    int maxDist = 0;

    while (!que.empty()) {
        vector<int> current = que.front();
        int x = current.at(0);
        int y = current.at(1);
        que.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + v.at(i);
            int ny = y + h.at(i);

            if (nx < 1 || nx > H || ny < 1 || ny > W) continue;
            if (dist.at(nx).at(ny) != -1) continue;
            if (s.at(nx).at(ny) == '#') continue;
            dist.at(nx).at(ny) = dist.at(x).at(y) + 1;
            que.push({nx, ny});
            maxDist = max(maxDist, dist.at(nx).at(ny));
        }
    }
    cout << maxDist << endl;

    return 0;
}