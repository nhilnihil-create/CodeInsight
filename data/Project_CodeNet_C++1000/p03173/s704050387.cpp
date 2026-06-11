#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    ll n;
    cin >> n;
    ll a[n+1];
    for(ll i = 1 ; i <= n ; i++)
    cin >>a[i];
    ll p[n+1];
    p[0] = 0;
    for(ll i = 1 ;i <= n ; i++)
    p[i] = p[i-1]+a[i];

    ll dp[n+1][n+1];

    for(ll i = 0 ; i <=  n ; i++)
    {
        for(ll j  = 0 ; j <= n ; j++)
        dp[i][j] = 1e18;
    }

    for(ll i = 1 ; i < n; i++)
    {
        dp[i][i+1] = a[i]+a[i+1];
        dp[i][i] = 0;
    }

    dp[n][n] = 0;

    


    for(ll k = 2 ; k< n ; k++)
    {
        for(ll j =  1 ; j <= n-k ; j++)
        {
            ll l = j , r = j+k;
            for(ll i = l ; i < r ; i++)
            {
                ll cost = dp[l][i]+dp[i+1][r] + p[i]-p[l-1] + p[r]-p[i];
                dp[l][r] = min(dp[l][r] , cost); 
            }
        }
    }


    cout << dp[1][n] ;

}
