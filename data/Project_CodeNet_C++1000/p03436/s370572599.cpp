#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int h, w;
    cin >> h >> w;

    vector<vector<int>> A;
    A.assign(h, vector<int>(w));

    int sum = 0;
    rep(i, h) rep(j, w)
    {
        char t;
        cin >> t;
        if (t == '.')
        {
            A[i][j] = 0;
            ++sum;
        }
        else
            A[i][j] = -1;
    }

    // BFS のためのデータ構造
    queue<pint> que;

    // initial state
    A[0][0] = 1;
    que.push(pint(0, 0));

    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};

    // bfs
    while (!que.empty())
    {
        pint v = que.front();
        que.pop();
        int i = v.first;
        int j = v.second;
        for (int k = 0; k < 4; ++k)
        {
            int ri = i + dx[k];
            int rj = j + dy[k];
            if (ri < 0 || ri >= h || rj < 0 || rj >= w)
                continue;
            if (A[ri][rj] == 0)
            {
                A[ri][rj] = A[i][j] + 1;
                que.push(pint(ri, rj));
            }
        }
    }

    // output
    if (A[h - 1][w - 1] == 0)
        cout << -1 << endl;
    else
    {
        cout << sum - A[h - 1][w - 1] << endl;
    }
}