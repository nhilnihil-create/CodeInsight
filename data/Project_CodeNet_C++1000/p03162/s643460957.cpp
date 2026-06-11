#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#include <bitset>
#define M 1000000007
#define M1 998244353

#define tr(container, it) \
    for (typeof(container.begin()) it = container.begin(); it != container.end(); it++)

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

ll power(ll x, ll n)
{
    ll result = 1;
    while (n)
    {
        if (n % 2 == 1)
            result = result * x;
        n = n / 2;
        x = x * x;
    }
    return result;
}

ll gcd(ll a, ll b)
{
    if (!b)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return (a * b) / gcd(a, b);
}

inline ll mul(ll x, ll y, ll m)
{
    ll z = 1LL * x * y;
    if (z >= m)
    {
        z %= m;
    }
    return z;
}

ll powmod(ll x, ll y, ll m)
{
    ll r = 1;
    while (y)
    {
        if (y & 1)
        {
            r = mul(r, x, m);
        }
        y >>= 1;
        x = mul(x, x, m);
    }
    return r;
}

void start()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
/***********************************************************************************************************/

int solve(vector<vector<int>> &a, int n, bool x, bool y, bool z, vector<vector<int>> &dp)
{
    if (n == 1)
    {
        if (x)
        {
            return dp[n][0] = max(a[n - 1][1], a[n - 1][2]);
        }
        if (y)
        {
            return dp[n][1] = max(a[n - 1][0], a[n - 1][2]);
        }
        return dp[n][2] = max(a[n - 1][0], a[n - 1][1]);
    }
    int b = 0, c = 0, d = 0;
    if (!x)
    {
        if (dp[n][0] != -1)
        {
            b = dp[n][0];
        }
        else
        {
            b = a[n - 1][0] + solve(a, n - 1, 1, 0, 0, dp);
            dp[n][0] = b;
        }
    }
    if (!y)
    {
        if (dp[n][1] != -1)
        {
            c = dp[n][1];
        }
        else
        {
            c = a[n - 1][1] + solve(a, n - 1, 0, 1, 0, dp);
            dp[n][1] = c;
        }
    }
    if (!z)
    {
        if (dp[n][2] != -1)
        {
            d = dp[n][2];
        }
        else
        {
            d = a[n - 1][2] + solve(a, n - 1, 0, 0, 1, dp);
            dp[n][2] = d;
        }
    }
    return max({b, c, d});
}

int main()
{
    start();
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(3, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>(3, -1));
    cout << solve(a, n, 0, 0, 0, dp);
    return 0;
}