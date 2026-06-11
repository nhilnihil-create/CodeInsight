#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> g(n, vector<int>(n, 0));
    for(int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;r--;
        g[l][r]++;
    }
    vector<int> x(q);
    vector<int> y(q);
    for(int i = 0; i < q; i++)
    {
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
    }
    vector<vector<int>> d(n+1, vector<int>(n+1, 0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            d[i+1][j+1] = d[i+1][j] + d[i][j+1] - d[i][j] + g[i][j];
        }
    }
    for(int i = 0; i < q; i++)
    {
        int l = x[i];
        int r = y[i]+1;
        cout << d[r][r] - d[r][l] - d[l][r] + d[l][l] << endl;
    }
}
