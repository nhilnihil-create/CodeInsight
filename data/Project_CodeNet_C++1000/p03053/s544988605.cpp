#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main()
{
    const int INF = 1 << 30;
    int h, w;
    cin >> h >> w;

    vector<string> a(h);
    for (int i = 0; i < h; i++) { cin >> a[i]; }

    queue<pair<int, int>> q;
    vector<vector<int>> d(h, vector<int>(w, INF));

    for (int x = 0; x < h; x++) {
        for (int y = 0; y < w; y++) {
            if (a[x][y] == '#') {
                q.push(make_pair(x, y));
                d[x][y] = 0;
            }
        }
    }

    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    while (!q.empty()) {
        auto nowpos = q.front();
        q.pop();
        int nowx = nowpos.first;
        int nowy = nowpos.second;
        for (int i = 0; i < 4; i++) {
            int newx = nowx + dx[i], newy = nowy + dy[i];
            if (newx < 0 || newx >= h || newy < 0 || newy >= w) continue;
            if (a[newx][newy] == '#') continue;
            if (d[newx][newy] != INF) continue;
            a[newx][newy] = '#';
            q.push(make_pair(newx, newy));
            d[newx][newy] = d[nowx][nowy] + 1;
        }
    }
    int ans = 0;
    for (int x = 0; x < h; x++) {
        for (int y = 0; y < w; y++) { ans = max(ans, d[x][y]); }
    }
    cout << ans << endl;
}