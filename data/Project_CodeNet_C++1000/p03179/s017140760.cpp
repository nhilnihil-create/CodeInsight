#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

const int N = 3009, MOD = 1e9 + 7;

int dp[N][N];
int sum[N][N];

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    s = "pu" + s;
    dp[1][1] = 1;
    for (int i = 1; i <= n; ++i)
        sum[1][i] = sum[1][i - 1] + dp[1][i];
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (s[i] == '<') {
                dp[i][j] = sum[i - 1][j - 1];
            }else{
                dp[i][j] = sum[i - 1][i - 1] - sum[i - 1][j - 1];
                if (dp[i][j] < 0)
                    dp[i][j] += MOD;
            }
            sum[i][j] = sum[i][j - 1] + dp[i][j];
            if (sum[i][j] >= MOD)
                sum[i][j] -= MOD;
        }
    }
    cout << sum[n][n];
    return 0;
}
