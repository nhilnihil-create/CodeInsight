#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

#define int long long
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(i, a) for (auto &i : (a))
#define sz(x) (int)(x).size()
#define all(v) (v).begin(), (v).end()
#define fr(i, a, b) for (int i = (a); i <= (b); ++i)
int arr[3005];
int dp[105][100005];
const int mod = 1e9 + 7;
signed main()
{
    clock_t beg = clock();
    // cout << fixed << setprecision(15);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    int a,k;
    cin >> a>>k;
    int arr[a];
    for (int i = 0; i < a; i++)
    {
        cin >> arr[i];
    }
    // memset(dp,0, sizeof(dp));
    for (int i = 0; i <= arr[0]; i++)
    {
        dp[0][i] = 1;
    }
    for (int i = 1; i < a; i++)
    {
        vector<int> prefixsum(k + 1);
        prefixsum[0] = dp[i - 1][0];
        for (int j = 1; j <= k; j++)
        {
            prefixsum[j] = (prefixsum[j - 1] + dp[i - 1][j])%mod;
        }
        for (int j = 0; j <= k; j++)
        {
            if (arr[i] >= j)
            {
                dp[i][j] = prefixsum[j];
            }
            else
            {
                int lol = j - arr[i] - 1;
                dp[i][j] = (prefixsum[j] +mod- prefixsum[lol]) % mod;
            }
        }
        prefixsum.clear();
    }
    cout << dp[a-1][k] << endl;
    return 0;
}
