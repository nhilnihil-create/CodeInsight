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
    int n, C;
    cin >> n >> C;
    vector<int> s(n), t(n), c(n);
    rep(i, n) cin >> s[i] >> t[i] >> c[i], s[i]--, c[i]--;
    int mn = MN(s);
    int mx = MX(t);
    vector<vector<int>> list(C, vector<int>(mx - mn, 0));
    rep(i, n)
    {
        for (int j = s[i] - mn; j < t[i] - mn; ++j)
            list[c[i]][j] = 1;
    }
    // cout << mn << " " << mx << endl;
    // rep(i, C)
    // {
    //     rep(j, mx - mn) cout << list[i][j] << " ";
    //     cout << endl;
    // }
    int ans = 0, res;
    rep(i, mx - mn + 1)
    {
        res = 0;
        rep(j, C) res += list[j][i];
        ans = max(ans, res);
    }
    cout << ans << endl;
}
int main(void)
{
    solve();
}