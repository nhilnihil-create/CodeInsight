#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[100001][2];
ll mod = 1e9+7;
vector<ll>v[100001];
ll add(ll x , ll y)
{
    x += y;
    if(x >= mod)
    x -= mod;

    return x;
}
void dfs(ll x , ll p)
{
    ll mult2 = 1  , mult1 = 1;
    for(ll i = 0 ; i < (ll)v[x].size() ; i++)
    {
        if(v[x][i] == p)
        continue;

        dfs(v[x][i] , x);
        ll num2 = add(dp[v[x][i]][1] , dp[v[x][i]][0]);
        mult2 = (mult2*num2)%mod;
        mult1 = (mult1 * dp[v[x][i]][1])%mod;
    }

    dp[x][0] = add(dp[x][0] , mult1);
    dp[x][1] = add(dp[x][1] , mult2);
}


int main() { 
    ll n;
    cin >> n;
    for(ll i =0 ; i < n-1 ; i++)
    {
        ll x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    dfs(1, 1);
    ll ans = add(dp[1][1] , dp[1][0]);
    cout << ans;
}
