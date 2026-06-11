#include <bits/stdc++.h>

typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
#define repr(i, n) for (ll i = n - 1; i >= 0; --i)
#define INF 10e12
#define MOD 1000000000 + 7
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))
using namespace std;

void solve(void)
{
    int n;
    cin >> n;
    vector<vector<int>> day(n, vector<int>(10));
    vector<vector<int>> cost(n, vector<int>(11));
    rep(i, n) rep(j, 10) cin >> day[i][j];
    rep(i, n) rep(j, 11) cin >> cost[i][j];
    ll ans = -INF;
    rep(i, 1 << 10)
    {
        if (i == 0)
            continue;
        vector<int> joisimo(10, 0);
        rep(j, 10) if (i >> j & 1) joisimo[j] = 1;
        ll res = 0;
        int cta;
        rep(j, n)
        {
            cta = 0;
            rep(k, 10) if (joisimo[k] == day[j][k] && joisimo[k] == 1)
                cta++;
            res += cost[j][cta];
        }
        ans = max(ans, res);
    }
    cout << ans << endl;
}
int main(void)
{
    solve();
}