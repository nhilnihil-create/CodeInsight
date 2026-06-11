#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ff first
#define ss second
#define pb push_back


int bexp(int a, int b, int mod)
{
    int res = 1;

    while (b)
    {
        if (b & 1) res = (res * a) % mod;

        a = (a * a) % mod; 
        b >>= 1;
    }
    return res;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

#define N 100010
#define MOD 1000000007

struct comp {
    bool operator() (const pair<int, int> a, const pair<int, int> b) const
    {
        return a.ss > b.ss;
    }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

    int n;
    cin >> n;
    int a[n][3];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 3; ++j)
            cin >> a[i][j];
    }

    int dp[2][3] = {};
    dp[0][0] = a[0][0];
    dp[0][1] = a[0][1];
    dp[0][2] = a[0][2];

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            dp[i % 2][j] = a[i][j] + max(dp[(i - 1) % 2][(j + 1) % 3], dp[(i - 1) % 2][(j + 2) % 3] );
        }
    }

    cout << *max_element(dp[(n - 1) % 2], dp[(n - 1) % 2] + 3);
    return 0;
}