#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;

void solve(long long N, std::vector<long long> a, std::vector<long long> b, std::vector<long long> c)
{

    vector<vec> dp(3, vec(N + 1));
    dp[0][0] = dp[1][0] = dp[2][0] = 0;

    for (ll i = 1; i <= N; i++)
    {
        dp[0][i] = max(dp[0][i], a[i - 1] + max(dp[1][i - 1], dp[2][i - 1]));
        dp[1][i] = max(dp[1][i], b[i - 1] + max(dp[0][i - 1], dp[2][i - 1]));
        dp[2][i] = max(dp[2][i], c[i - 1] + max(dp[1][i - 1], dp[0][i - 1]));
    }
    ll ans = max(dp[0][N], dp[1][N]);
    ans = max(ans, dp[2][N]);
    cout << ans << endl;
}

signed main()
{
    long long N;
    scanf("%lld", &N);
    std::vector<long long> a(N);
    std::vector<long long> b(N);
    std::vector<long long> c(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &a[i]);
        scanf("%lld", &b[i]);
        scanf("%lld", &c[i]);
    }
    solve(N, std::move(a), std::move(b), std::move(c));
    return 0;
}
