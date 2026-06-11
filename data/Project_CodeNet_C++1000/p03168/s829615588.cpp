#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <class T> using oset = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;

void usaco(string name = "")
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if(name.size())
    {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

#define ld long double

int32_t main()
{
    usaco();
    ld n;
    cin >> n;
    vector <ld> p(n+1);
    for (int i = 1; i <= n; ++i) cin >> p[i];
    vector <vector <ld>> dp(n+1, vector <ld> (n+1));
    dp[1][0] = ((ld)1)-p[1];
    dp[1][1] = p[1];
    for (int i = 2; i <= n; ++i)
    {
        dp[i][0] = dp[i-1][0] * (((ld)1)-p[i]);
        dp[i][i] = dp[i-1][i-1] * p[i];
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j < i; ++j)
            dp[i][j] = dp[i-1][j] * (((ld)1)-p[i]) + dp[i-1][j-1] * p[i];
    ld ans = 0;
    for (int i = n/2+1; i <= n; ++i) ans += dp[n][i];
    cout << fixed << setprecision(10) << ans << '\n';
}
