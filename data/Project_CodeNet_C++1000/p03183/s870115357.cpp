#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxn = 1010, maxl = 10010;
int dp[maxn][maxl], n;

struct item
{
    int w, s, v;
} a[maxn];

signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i].w >> a[i].s >> a[i].v;
    sort(a, a + n, [](item u, item v) { return u.w + u.s > v.w + v.s; });

    for (int i = n - 1; ~i; i--)
        for (int j = 0; j < maxl; j++)
        {
            item u = a[i];
            dp[i][j] = dp[i + 1][j];
            if (j >= u.w)
                dp[i][j] = max(dp[i][j], dp[i + 1][min(j - u.w, u.s)] + u.v);
        }

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, dp[i + 1][a[i].s] + a[i].v);

    cout << ans;

    return 0;
}
