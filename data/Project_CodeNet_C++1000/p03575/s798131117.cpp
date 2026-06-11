#include <bits/stdc++.h>
    using namespace std;
     
    const int M = 50;
     
    int n, m,g[M+10][M+10];
    pair<int, int> a[M+10];
    bool bo[M + 10];
     
    void dfs(int x)
    {
        if (bo[x]) return;
        bo[x] = true;
        for (int i = 1;i <= n;i++)
            if (i!=x && g[x][i])
                dfs(i);
    }
     
    int main()
    {
        //freopen("F:\\rush.txt", "r", stdin);
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            g[x][y] = g[y][x] = 1;
            a[i] = make_pair(x, y);
        }
     
        int ans = 0;
        for (int i = 1; i <= m; i++)
        {
            g[a[i].first][a[i].second] = 0;
            g[a[i].second][a[i].first] = 0;
            for (int j = 1; j <= n; j++) bo[j] = 0;
            dfs(1);
            int ok = false;
            for (int j = 1; j <= n; j++)
                if (bo[j] == 0)
                    ok = 1;
            ans += ok;
            g[a[i].first][a[i].second] = 1;
            g[a[i].second][a[i].first] = 1;
        }
        printf("%d\n", ans);
        return 0;
    }