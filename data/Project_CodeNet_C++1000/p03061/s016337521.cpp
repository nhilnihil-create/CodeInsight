#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5, mod = 1e9 + 7;

int a[N], dp[N][2], n;

int solve(int i, int taken)
{
    if (i == n - 1)
    {
        if (taken)
            return a[i];
        return 0;
    }
    if (dp[i][taken] != -1)
        return dp[i][taken];
    int ans = 0;
    if (taken)
        ans = __gcd(solve(i + 1, 1), a[i]);
    else
        ans = max(__gcd(solve(i + 1, 0), a[i]), solve(i + 1, 1));
    return dp[i][taken] = ans;
}

int main()
{
    //ios::sync_with_stdio(false);cin.tie(nullptr);ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0);
    return 0;
}