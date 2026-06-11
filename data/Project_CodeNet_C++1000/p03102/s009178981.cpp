#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> b(m);
    rep(i, m) cin >> b[i];
    vector<vector<int>> a(n, vector<int>(m));
    rep(i, n) rep(j, m) cin >> a[i][j];
    int ans = 0;
    rep(i, n)
    {
        int s = c;
        rep(j, m)
        {
            s += a[i][j] * b[j];
        }
        if (s > 0)
            ans++;
    }
    cout << ans << endl;
    return 0;
}