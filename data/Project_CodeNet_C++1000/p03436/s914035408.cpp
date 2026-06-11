#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<char>> grid(h, vector<char>(w));
    vector<vector<int>> score(h, vector<int>(w, INF));
    int all = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == '.')
            {
                ++all;
            }
        }
    }

    queue<P> qe;
    qe.push(make_pair(0, 0));
    score[0][0] = 0;
    while (!qe.empty())
    {
        P now = qe.front();
        qe.pop();
        int xs[4] = {1, -1, 0, 0};
        int ys[4] = {0, 0, 1, -1};
        for (int i = 0; i < 4; i++)
        {
            P next = make_pair(now.first + xs[i], now.second + ys[i]);
            if (next.first < 0 || next.second < 0 || next.first >= h || next.second >= w)
            {
                continue;
            }
            if (grid[next.first][next.second] == '#')
            {
                continue;
            }
            if (score[now.first][now.second] >= score[next.first][next.second] + 1)
            {
                continue;
            }
            if (score[next.first][next.second] != INF)
            {
                score[next.first][next.second] = score[now.first][now.second] + 1;
                continue;
            }

            // cout << next.first << ':' << next.second << endl;
            score[next.first][next.second] = score[now.first][now.second] + 1;
            qe.push(next);
        }
    }
    if (score[h - 1][w - 1] == INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << all - score[h - 1][w - 1] - 1 << endl;
    }
    return 0;
}

// Use For Debug
template <typename T>
void print(T const &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
}