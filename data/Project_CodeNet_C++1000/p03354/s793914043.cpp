#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for (int i = x; i < n; i++)
#define OP(m) cout << m << endl
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int const N = 50001;

/*void dfs(int u, int c)
{
    connect[u] = c;
    rep(i, G[u].size())
    {
        if (connect[G[u][i]] == -1)
        {
            dfs(G[u][i], c);
        }
    }
    return;
}*/

int main()
{
    int n, m;
    cin >> n >> m;
    int p[n] = {};
    vector<int> G[n];
    vector<int> connect(n, -1);
    rep(i, n)
    {
        cin >> p[i];
        p[i]--;
    }

    rep(i, n)
        connect[i] = -1;

    rep(i, m)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    int cnt = 0;

    rep(u, n)
    {
        if (connect[u] != -1)
            continue;
        queue<int> q;
        q.push(u);
        cnt++;
        while (!q.empty())
        {

            int v = q.front();
            connect[v] = cnt;
            q.pop();
            rep(i, G[v].size())
            {
                if (connect[G[v][i]] == -1)
                    q.push(G[v][i]);
            }
        }
    }

    int ans = 0;
    rep(i, n) if (connect[i] == connect[p[i]]) ans++;

    OP(ans);

    return 0;
}