#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;
const int N = 10, M = 1e7 + 5;
ll d, g, p[N], c[N], dp[N][M];
ll solve(int i, ll rem)
{
    if(i == d)          return (!rem ? 0 : 1e18);
    if(~dp[i][rem])     return dp[i][rem];
    ll ans = solve(i + 1, max(rem - c[i] - p[i] * (i + 1), 0LL)) + p[i];
    for(int j = 0;j < p[i];++j)
        ans = min(ans, solve(i + 1, max(rem - j * (i + 1), 0LL)) + j);
    return dp[i][rem] = ans;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> d >> g;
    g /= 100;
    for(int i = 0;i < d;++i)
    {
        cin >> p[i] >> c[i];
        c[i] /= 100;
    }
    memset(dp, -1, sizeof dp);
    cout << solve(0, g);
    return 0;
}
