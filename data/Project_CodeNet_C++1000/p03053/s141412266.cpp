#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <bits/stdc++.h>
#include <iomanip>
#include <numeric>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (ll i = a; i < (ll)b; ++i)
#define P pair<ll, ll>
#define INF 10e12
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main(void)
{
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, 0, h) cin >> s[i];
    vector<vector<int>> dist(h, vector<int>(w, -1));
    queue<P> que;
    rep(i, 0, h) rep(j, 0, w) if (s[i][j] == '#') que.push({i, j}), dist[i][j] = 0;
    while (!que.empty())
    {
        int y = que.front().first, x = que.front().second;
        que.pop();
        rep(i, 0, 4)
        {
            int ny = y + dy[i], nx = x + dx[i];
            if (0 <= ny && ny < h && 0 <= nx && nx < w && dist[ny][nx] == -1)
                dist[ny][nx] = dist[y][x] + 1, que.push({ny, nx});
        }
    }
    int ans = 0;
    rep(i, 0, h) ans = max(ans, MX(dist[i]));
    cout << ans << endl;
}