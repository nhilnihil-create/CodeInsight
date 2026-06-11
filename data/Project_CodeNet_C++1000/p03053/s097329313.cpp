#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
static const int INFTY = (1 << 30);
int H, W;
int func2(vector<vector<bool>> &a, vector<vector<bool>> &v)
{
    int r[H][W] = {};
    int ans;
    queue<pair<int, int>> q;
    rep(i, 0, H)
    {
        rep(j, 0, W)
        {
            if (a[i][j])
            {
                q.push(make_pair(j, i));
                v[i][j] = true;
                r[i][j] = 0;
            }
        }
    }
    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        ans = r[y][x];
        q.pop();
        if (x > 0 && !v[y][x - 1])
        {
            r[y][x - 1] = ans + 1;
            v[y][x - 1] = true;
            a[y][x - 1] = true;
            q.push(make_pair(x - 1, y));
        }
        if (x < W - 1 && !v[y][x + 1])
        {
            r[y][x + 1] = ans + 1;
            v[y][x + 1] = true;
            a[y][x + 1] = true;
            q.push(make_pair(x + 1, y));
        }
        if (y > 0 && !v[y - 1][x])
        {
            r[y - 1][x] = ans + 1;
            v[y - 1][x] = true;
            a[y - 1][x] = true;
            q.push(make_pair(x, y - 1));
        }
        if (y < H - 1 && !v[y + 1][x])
        {
            r[y + 1][x] = ans + 1;
            v[y + 1][x] = true;
            a[y + 1][x] = true;
            q.push(make_pair(x, y + 1));
        }
    }
    return ans;
}
void func()
{
    cin >> H >> W;
    vector<vector<bool>> a(H, vector<bool>(W));
    vector<vector<bool>> v(H, vector<bool>(W, false));
    rep(i, 0, H)
    {
        string tmpstr;
        cin >> tmpstr;
        rep(j, 0, W)
            a[i][j] = (tmpstr[j] == '#') ? true : false;
    }
    cout << func2(a, v) << endl;
}
int main()
{
    func();
}