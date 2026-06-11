#include <bits/stdc++.h>

typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
#define repr(i, n) for (ll i = n - 1; i >= 0; --i)
#define INF 10e8
#define MOD 1000000000 + 7
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))
using namespace std;

void solve(void)
{
    int h, w;
    cin >> h >> w;
    vector<vector<int>> c(10, vector<int>(10));
    rep(i, 10) rep(j, 10) cin >> c[i][j];
    vector<vector<int>> a(h, vector<int>(w));
    rep(i, h) rep(j, w) cin >> a[i][j];

    rep(k, 10) rep(i, 10) rep(j, 10) c[i][j] = min(c[i][j], c[i][k] + c[k][j]);

    int ans = 0;
    rep(i, h) rep(j, w) if (a[i][j] != -1) ans += c[a[i][j]][1];
    cout << ans << endl;
}
int main(void)
{
    solve();
}