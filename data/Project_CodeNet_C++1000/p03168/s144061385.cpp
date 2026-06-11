#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define F first
#define S second
#define Tsetso ios_base::sync_with_stdio(0) ; cin.tie(0) ;
using namespace std;
const ll N = 3000, inf = 1e3+5, mod = 1e9+7, NN = 1e5+10;
int n ;
ld dp[3005][3005], a[N];
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    dp[1][0] = 1.0 - a[1];
    for(int i = 2; i <= n; ++i)
        dp[i][0] = dp[i - 1][0] * (1.0 - a[i]);

    dp[1][1] = a[1];
    for(int i = 2; i <= n; ++i)
        dp[i][i] = dp[i - 1][i - 1] * a[i];

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j < i; ++j)
            dp[i][j] = dp[i - 1][j] * (1.0 - a[i]) + dp[i - 1][j - 1] * a[i];
    }

    for(int i = n / 2 + 1; i < n; ++i)
        dp[n][n] += dp[n][i];
    cout << fixed << setprecision(10) << dp[n][n];
    return 0;
}
