#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int h, w;
    cin >> h >> w;
    int count = 0;
    char b[h][w];
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> b[i][j];
            if (b[i][j] == '.')
                count++;
        }
    }
    int dh[4] = {-1, 1, 0, 0};
    int dw[4] = {0, 0, 1, -1};
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    vector<vector<bool>> visited(h, vector<bool>(w, 0));
    int ans[h][w];
    ans[0][0] = 1;
    ans[h - 1][w - 1] = -1;
    while (!q.empty())
    {
        pair<int, int> cr = q.front();
        q.pop();
        if (cr.first == h - 1 && cr.second == w - 1)
            break;
        for (int i = 0; i < 4; i++)
        {
            int nh = cr.first + dh[i];
            int nw = cr.second + dw[i];
            if (nh > h - 1 || nh < 0 || nw > w - 1 || nw < 0 ||
                b[nh][nw] == '#' || visited[nh][nw] == 1)
                continue;
            else
            {
                q.push(make_pair(nh, nw));
                visited[nh][nw] = 1;
                ans[nh][nw] = ans[cr.first][cr.second] + 1;
            }
        }
    }
    if (ans[h - 1][w - 1] == -1)
        cout << -1 << endl;
    else
        cout << count - ans[h - 1][w - 1] << endl;
}