#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int h, w;
    cin >> h >> w;

    vector<vector<int>> c(10, vector<int>(10));
    rep(i, 10) rep(j, 10) cin >> c[i][j];

    vector<vector<int>> a(h, vector<int>(w));
    rep(i, h) rep(j, w) cin >> a[i][j];

    for (int k = 0; k < 10; k++)
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                c[i][j] = min(c[i][j], c[i][k] + c[k][j]);

    int ans = 0;
    rep(i, h) rep(j, w) if (a[i][j] != -1) ans += c[a[i][j]][1];
    cout << ans << endl;
}