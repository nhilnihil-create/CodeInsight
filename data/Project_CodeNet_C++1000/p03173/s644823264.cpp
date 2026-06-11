#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
#define MOD 1000000007
#define int long long
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
#define ff first
#define ss second
#define INF (1LL<<61)

using namespace std;


int n ;
int a[410];
int sum[410];
int dp[410][410];

int solve(int i , int j) {

    if (i == j)return 0;

    if (dp[i][j] != -1)return dp[i][j];

    int cost = INF;

    for (int k  = i ; k <= j - 1 ; k++) {
        cost = min(cost , sum[j] - sum[i - 1] + solve(i , k) + solve(k + 1 , j));
    }

    return dp[i][j] = cost;
}

int32_t main() {

    fastio
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    memset(dp , -1, sizeof(dp));
    cin >> n;
    for (int i = 1; i <= n ; i++)cin >> a[i];

    for (int i = 1; i <= n ; i++)sum[i] = sum[i - 1] + a[i];

    cout << solve(1, n) << '\n';

    return 0;
}
