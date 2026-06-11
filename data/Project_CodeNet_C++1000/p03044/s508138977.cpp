#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int n;
    cin >> n;

    vector<vector<pint>> A(n);
    rep(i, n - 1)
    {
        int u, v, w;
        cin >> u >> v >> w, --u, --v;
        A[u].emplace_back(pint(w, v));
        A[v].emplace_back(pint(w, u));
    }

    // BFS のためのデータ構造
    vector<ll> dist(n, -1);
    queue<int> que;

    // initial state
    dist[0] = 0;
    que.push(0);

    // bfs
    while (!que.empty())
    {
        int v = que.front();
        que.pop();

        for (pint nv : A[v])
        {
            if (dist[nv.second] != -1)
                continue;

            dist[nv.second] = dist[v] + nv.first;
            que.push(nv.second);
        }
    }

    // output
    rep(i, n)
    {
        if (dist[i] % 2 == 0)
            cout << 0 << endl;
        else
            cout << 1 << endl;
    }
}