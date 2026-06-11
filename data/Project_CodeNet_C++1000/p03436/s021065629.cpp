#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
static const int INFTY = (1 << 30);
int H, W;
int msearch(vector<vector<bool>> &s)
{
    queue<pair<int, int>> q;
    bool v[H][W] = {};
    int r[H][W] = {};
    q.push(make_pair(0, 0));
    v[0][0] = true;
    r[0][0] = 0;
    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        if (x == W - 1 && y == H - 1)
            return r[H - 1][W - 1] + 1;
        if (x > 0 && s[y][x - 1] && !v[y][x - 1])
        {
            r[y][x - 1] = r[y][x] + 1;
            v[y][x - 1] = true;
            q.push(make_pair(x - 1, y));
        }
        if (x < W - 1 && s[y][x + 1] && !v[y][x + 1])
        {
            r[y][x + 1] = r[y][x] + 1;
            v[y][x + 1] = true;
            q.push(make_pair(x + 1, y));
        }
        if (y > 0 && s[y - 1][x] && !v[y - 1][x])
        {
            r[y - 1][x] = r[y][x] + 1;
            v[y - 1][x] = true;
            q.push(make_pair(x, y - 1));
        }
        if (y < H - 1 && s[y + 1][x] && !v[y + 1][x])
        {
            r[y + 1][x] = r[y][x] + 1;
            v[y + 1][x] = true;
            q.push(make_pair(x, y + 1));
        }
    }
    return -1;
}
void func()
{
    cin >> H >> W;
    vector<vector<bool>> s(H, vector<bool>(W));
    rep(i, 0, H)
    {
        string tmpstr;
        cin >> tmpstr;
        rep(j, 0, W)
        {
            s[i][j] = (tmpstr[j] == '.') ? true : false;
        }
    }
    int max = 0;
    rep(i, 0, H)
    {
        rep(j, 0, W)
        {
            if (s[i][j])
                ++max;
        }
    }
    int ans = msearch(s);
    // cout << ans << ' ' << max << endl;
    if (ans != -1)
        ans = max - ans;
    cout << ans << endl;
}
int main()
{
    func();
}