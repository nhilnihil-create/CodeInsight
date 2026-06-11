#include <bits/stdc++.h>
using namespace std;

int H, W;
int white_num = 0;
vector<vector<char>> maze(H, vector<char>(W));
vector<vector<int>> dist(H, vector<int>(W, -1));

void input()
{
    cin >> H >> W;
    maze = vector<vector<char>> (H, vector<char>(W));
    dist = vector<vector<int>> (H, vector<int>(W, -1));
    for (int i=0; i<H; i++)
    {
        string row;
        cin >> row;
        for (int j=0; j<W; j++)
        {
            maze[i][j] = row[j];
            if (row[j]=='.') white_num++;
        }
    }
}

void solve()
{
    auto check = [](int h, int w)
    {
        if (h>=0 && h<H && w>=0 && w<W && maze[h][w]=='.' && dist[h][w]==-1) return true;
        else return false;
    };

    int dh[4] = {1, -1, 0, 0};
    int dw[4] = {0, 0, 1, -1};

    queue<pair<int, int>> que;
    pair<int, int> start={0, 0};
    dist[0][0] = 1;
    que.push(start);

    while(!que.empty())
    {
        pair<int, int> v = que.front();
        que.pop();
        for (int i=0; i<4; i++)
        {
            pair<int, int> next;
            next.first = v.first + dh[i];
            next.second = v.second + dw[i];
            if (check(next.first, next.second))
            {
                que.push(next);
                dist[next.first][next.second] = dist[v.first][v.second]+1;
            }
        }
    }
    int ans;
    if (dist[H-1][W-1]!=-1) ans = white_num - dist[H-1][W-1];
    else ans = -1;
    cout << ans << endl;

    //デバッグ用
    /*
    for (int i=0; i<H; i++)
    {
        for (int j=0; j<W; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    */
}

int main()
{
    input();
    solve();
}