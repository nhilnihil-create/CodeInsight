#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9+7;
ll n;
string x;
ll dp[3001][3001];

int main() {
    cin >> n;
    cin >> x;
    
    dp[1][1] = 1;
    for(ll i = 2 ; i <= n ; i++)
    {
        for(ll j = 1 ; j <= i-1 ; j++)
        {
            dp[i-1][j] += dp[i-1][j-1];
            if(dp[i-1][j] >= mod)
            dp[i-1][j] -= mod;
        }
        for(ll j = 1 ; j <= i ; j++)
        {
            if(x[i-2] == '<')
            {
                dp[i][j] += dp[i-1][j-1];
                if(dp[i][j] >= mod)
                dp[i][j] -= mod;
            }
            else
            {
                ll temp = (dp[i-1][i-1]-dp[i-1][j-1]);
                if(temp < 0)
                temp += mod;
                dp[i][j] += temp;
                if(dp[i][j] >= mod)
                dp[i][j] -= mod;
            }
        }
    }
    ll ans= 0;
    for(ll i = 1; i <= n ; i++)
    {
        ans += dp[n][i];
        if(ans >= mod)
        ans -= mod;
    }
    cout << ans;
}
