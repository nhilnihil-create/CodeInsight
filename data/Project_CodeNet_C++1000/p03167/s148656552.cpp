#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int H, W;
ll dp[1009][1009];
char c[1009][1009];
const ll MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> H >> W;
    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            cin >> c[i][j];
        }
    }

    dp[0][1] = 1;
    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (c[i][j] == '.')
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                dp[i][j] %= MOD;
                dp[i][j] += MOD;
                dp[i][j] %= MOD;
            }
        }
    }

    cout << dp[H][W];
}