#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define sz(x) ((int)x.size())

const int mod = 1000*1000*1000 + 7;
int dp[3005][3005] = {{0}};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    dp[1][1] = 1;
    for(int i = 2; i <= n; i++)
    {
        int sum = 0;
        if(s[i-2] == '<')
        {
            for(int k = 1; k <= i; k++)
            {
                dp[i][k] = sum;
                sum += dp[i-1][k];
                sum %= mod;
            }
        }
        else
        {
            for(int k = i; k >= 1; k--)
            {
                sum += dp[i-1][k];
                sum %= mod;
                dp[i][k] = sum;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) 
        ans += dp[n][i], ans %= mod;
    cout << ans << endl;
}