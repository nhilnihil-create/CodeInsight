#include <iostream>
#include <iomanip>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>
#include <stack>
#define pb push_back
// #define pop pop_back
#define ll long long int
#define vi vector<int>
#define vl vector<long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long>>
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep2(i, a, b) for (ll i = a; i <= b; i++)
#define repr(i, a, b) for (ll i = a; i >= b; i--)
#define I long_max
#define pii pair<int, int>
#define pll pair<long, long>
#define vpair vector<pair<int, int>>
#define mp make_pair
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define fir first
#define sec second
#define d (int)1e9 + 7
#define INF (int)2e9 + 1
#define el "\n"
#define fs fastscan

#define vrep(vec) for (const auto &value : vec)
#define arep(arrat) for (const auto &value : array)
using namespace std;

bool sortinrev(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.first > b.first);
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//over

bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

ll dfs(ll n, vector<vector<ll>> &adj, vector<ll> &dp)
{
    for (ll j = 0; j < adj[n].size(); j++)
    {
        if (dp[adj[n][j]] == -1)
        {
            if (dp[n] == -1)
            {
                dp[n] = 0;
            }
            dp[n] = max(dp[n], 1 + dfs(adj[n][j], adj, dp));
        }
        else
        {
            if (dp[n] == -1)
            {
                dp[n] = 0;
            }
            dp[n] = max(dp[n], 1 + dp[adj[n][j]]);
        }
    }
    if (dp[n] == -1)
    {
        return dp[n] = 0;
    }
    return dp[n];
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //use auto instead of data types
    {
        ll n, m;
        cin >> n >> m;
        vector<vector<char>> a(n, vector<char>(m, 0));
        rep(i, n)
        {
            rep(j, m)
            {
                cin >> a[i][j];
            }
        }
        vector<vector<ll>> dp(n+1,vector<ll>(m+1,0));
        dp[n-1][m-1] = 1;
        for(int i = n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                if(a[i][j] == '.'){
                    dp[i][j] = dp[i][j] + dp[i+1][j] + dp[i][j+1];
                    dp[i][j] = dp[i][j] % int(1e9+7);
                }
            }
        }
        // ll count = 0;
        
        cout << dp[0][0] << endl;
    }
    return 0;
}