#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define sz(x) ((int)x.size())

long double dp[3000] = {0.0L};
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, target;
    cin >> n;
    target = (n+1)/2;
    dp[0] = 1.0L;
    while(n--)
    {
        long double p;
        cin >> p;
        for(int i = 2999; i > 0; i--)
            dp[i] = dp[i]*(1.0L - p) + dp[i-1]*p;
        dp[0] = dp[0]*(1.0L - p);
    }
    long double ans = 0.0L;
    for(int i = target; i <= 2999; i++)
        ans += dp[i];
    cout << setprecision(15) << ans << endl;
}