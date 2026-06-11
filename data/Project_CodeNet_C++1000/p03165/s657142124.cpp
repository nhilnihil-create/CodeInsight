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
    
    string s, t;
    cin >> s >> t;

    int n1 = s.size(), n2 = t.size();

    int dp[n1][n2] = {}, p[n1][n2] = {};

    for (int i = 0; i < n1; ++i)
    {
        for (int j = 0; j < n2; ++j)
        {
            if (s[i] == t[j])
            {
                dp[i][j] = (j > 0 && i > 0 ? dp[i - 1][j - 1] : 0) + 1;
                p[i][j] = 1;
            }
            else
            {
                dp[i][j] = (i > 0 ? dp[i - 1][j] : 0);

                if ((j > 0 ? dp[i][j - 1] : 0) > dp[i][j])
                {
                    dp[i][j] = (j > 0 ? dp[i][j - 1] : 0);
                    p[i][j] = 2;
                }
            }
        }
    }    

    string ans;

    int i = n1 - 1, j = n2 - 1;

    while (i >= 0 && j >= 0)
    {
        // cout << i << " " << j << " " << p[i][j] << endl;
        if (p[i][j] == 1)
        {
            ans += s[i];
            i -= 1, j -= 1;
        }
        else if (p[i][j] == 2)
        {
            j -= 1;
        }
        else
            i -= 1;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}