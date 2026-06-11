#include <bits/stdc++.h>
using namespace std;

/*
最短経路をもとめて、経路上以外の.のマスの数を求めればよい.
グリッド上の'.'の数 - 最短経路で通った'.'の数

ゴールにたどり着けない場合は-1を出力。
*/

const int INF = 1e9;
typedef pair<int, int> P;

vector<int> di = {1, 0, -1, 0};
vector<int> dj = {0, 1, 0, -1};

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<char>> maze(H, vector<char>(W));
    int num_white = 0;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            char c; cin >> c;
            maze[i][j] = c;

            if (c == '.') {
                num_white++;
            }
        }
    }
    num_white -= 2; // distract for start and goal white

    // init dist
    vector<vector<int>> dist(H, vector<int>(W, INF));

    // init start
    dist[0][0] = 0;
    queue<P> que;
    que.push(P(0, 0));

    // BFS
    while (que.size() > 0)
    {
        P p = que.front(); que.pop();

        // goal break
        if (p.first == H-1 && p.second == W-1) {
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int ni = p.first + di[i];
            int nj = p.second + dj[i];

            if (0 <= ni && ni < H && 0 <= nj && nj < W) {
                if (maze[ni][nj] != '#' && dist[ni][nj] == INF) {
                    que.push(P(ni, nj));
                    dist[ni][nj] = dist[p.first][p.second] + 1;
                }
            }
        }
    }

    int goal_dist = dist[H - 1][W - 1];
    if (goal_dist == INF) {
        cout << -1 << endl;
    }
    else {
        goal_dist--; // distract for moving to goal
        cout << num_white - goal_dist << endl;
    }
    


}