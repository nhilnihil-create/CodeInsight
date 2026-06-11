#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
string board[MAXN];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool visited[MAXN][MAXN];

int main()
{
    int h, w;
    cin >> h >> w;
    queue<tuple<int, int, int>> q;
    for (int i = 0; i < h; i++)
    {
        cin >> board[i];
        for (int j = 0; j < w; j++)
        {
            if (board[i][j] == '#')
            {
                visited[i][j] = true;
                q.push(make_tuple(i, j, 0));
            }
        }
    }
    int ans = 0;
    while (!q.empty())
    {
        tuple<int, int, int> tup = q.front();
        q.pop();
        ans = get<2>(tup);
        int r = get<0>(tup);
        int c = get<1>(tup);
        for (int i = 0; i < 4; i++)
        {
            int newr = r + dx[i];
            int newc = c + dy[i];
            if (newr < 0 || newr >= h || newc < 0 || newc >= w || visited[newr][newc])
                continue;
            q.push(make_tuple(newr, newc, get<2>(tup) + 1));
            visited[newr][newc] = true;
        }
    }
    cout << ans << "\n";
    return 0;
}
