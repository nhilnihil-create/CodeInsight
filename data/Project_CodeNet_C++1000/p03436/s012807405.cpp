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

    vector<vector<int>> seen(h, vector<int>(w, -1));
    int cta = 0, ans = 0;
    rep(i, 0, h) rep(j, 0, w) if (s[i][j] == '.') cta++;
    queue<P> que;
    P a = {0, 0};
    que.push(a);
    seen[0][0] = 0;
    while (!que.empty())
    {
        P tmp = que.front();
        que.pop();
        rep(i, 0, 4)
        {
            int ny = tmp.first + dy[i], nx = tmp.second + dx[i];
            if (ny < 0 || h <= ny || nx < 0 || w <= nx)
                continue;
            if (s[ny][nx] == '#')
                continue;
            if (seen[ny][nx] == -1)
            {
                seen[ny][nx] = seen[tmp.first][tmp.second] + 1;
                P b = {ny, nx};
                que.push(b);
            }
        }
    }
    if (seen[h - 1][w - 1] == -1)
        ans = -1;
    else
        ans = cta - seen[h - 1][w - 1] - 1;
    cout << ans << endl;
}