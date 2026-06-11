#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int H, W, h, w;
    cin >> H >> W >> h >> w;
    vector<vector<int>> a(H, vector<int>(W));
    rep(i, h) rep(j, W) a[i][j] = 1;
    rep(i, H) rep(j, w) a[i][j] = 1;
    int ans = 0;
    rep(i, H) rep(j, W) if (a[i][j] == 0) ans++;
    cout << ans << endl;
    return 0;
}