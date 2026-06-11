#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int h, w;
    cin >> h >> w;
    string board[h];
    rep(i, h) cin >> board[i];
    int dy[4] = {1, 0, -1, 0};
    int dx[4] = {0, 1, 0, -1};
    vector<vector<bool>> check(h, vector<bool>(w, false));
    rep(i, h)
    {
        rep(j, w)
        {
            if (board[i][j] == '#')
            {
                rep(k, 4)
                {
                    int y = j + dy[k];
                    int x = i + dx[k];
                    if (x < 0 || x >= h || y < 0 || y >= w)
                        continue;
                    if (board[x][y] == '#')
                        check[i][j] = true;
                }
            }
        }
    }
    bool ok = true;
    rep(i, h)
    {
        rep(j, w)
        {
            if (board[i][j] == '#' && check[i][j] == false)
                ok = false;
        }
    }
    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}