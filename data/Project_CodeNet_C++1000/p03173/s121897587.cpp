#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define ll long long
#define MOD 1000000007

ll sum[401];

ll solve(vector<int> &vec, int l, int r, vector<vector<ll>> &dp){
    if (l>r)
        return INT64_MAX;
    if (r==l)
        return 0;
    if (dp[l][r]!=INT64_MAX)
        return dp[l][r];

    ll ans = INT64_MAX;
    ll val = sum[r]-sum[l-1];
    for (int i=l; i<r; i++){
        ans = min(ans, solve(vec, l, i, dp)+solve(vec, i+1, r, dp) + val);
    }
    return dp[l][r] = ans;
}

signed main() {
    //freopen("input1.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> vec(n+1);

    for (int i=1; i<=n; i++)
        cin >> vec[i];
    
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, INT64_MAX));
    
    sum[0]=0;
    for (int i=1; i<=n; i++)
        sum[i] = sum[i-1]+vec[i];
    
    cout << solve(vec, 1, n, dp);
    
    return 0;
}