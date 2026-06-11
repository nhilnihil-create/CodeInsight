#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> FI(h);
    rep(i, h) cin >> FI[i];

    vector<vector<int>> dist(h, vector<int>(w, -1));
    dist[0][0] = 0;
    queue<pair<int, int>> que;
    que.push(make_pair(0, 0));
    while (!que.empty())
    {
        pair<int, int> current_pos = que.front();
        int y = current_pos.first;
        int x = current_pos.second;
        que.pop();
        for (int direction = 0; direction < 4; ++direction)
        {
            int next_x = x + dx[direction];
            int next_y = y + dy[direction];
            if (next_y < 0 || next_y >= h || next_x < 0 || next_x >= w)
                continue;
            if (FI[next_y][next_x] == '#')
                continue;

            if (dist[next_y][next_x] == -1)
            {
                que.push(make_pair(next_y, next_x));
                dist[next_y][next_x] = dist[y][x] + 1;
            }
        }
    }
    if (dist[h - 1][w - 1] == -1)
    {
        cout << -1 << endl;
        return 0;
    }
    int cnt = 0;
    rep(y, h)
    {
        rep(x, w)
        {
            if (FI[y][x] == '.')
                cnt++;
        }
    }
    cout << cnt - dist[h - 1][w - 1] - 1 << endl;
}