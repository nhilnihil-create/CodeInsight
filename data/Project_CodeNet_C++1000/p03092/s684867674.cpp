#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pb emplace_back

const int MAXN = 5009;
int dp[MAXN];
int a[MAXN];
int n, x, y;
int inf = 1ll * 1000 * 1000 * 1000 * 1000 * 1000 * 1000;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> y >> x;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[n + 1] = n + 1;
    n += 2;
    for (int i = 1; i < n; i++)
    {
        dp[i] = inf;
        int cur = 0;
        int ma = -1;
        for (int e = i - 1; e >= 0; e--)
        {
            if (a[e] < a[i] && (ma == -1 || a[e] > ma))
                dp[i] = min(dp[i], dp[e] + cur);
            if (a[e] > a[i])
                cur += y;
            else
            {
                cur += x;
                if (ma == -1)
                    ma = a[e];
                else
                    ma = max(ma, a[e]);
            }
        }
    }
    cout << dp[n - 1];
}