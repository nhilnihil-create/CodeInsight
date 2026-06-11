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

   
    int n, k;
    cin >> n >> k;

    int h[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> h[i];
    }
        
    int dp[k] = {};

    for (int i = 1; i < n; ++i)
    {
        int k1 = INT_MAX;
        for (int j = 1; j <= k; ++j)
            if (i - j >= 0)
                k1 = min(k1, dp[k - j] + abs(h[i] - h[i - j]));

        for (int j = 0; j < k - 1; ++j)
            dp[j] = dp[j + 1];
        dp[k - 1] = k1;
    }

    cout << dp[k - 1];
    return 0;
}