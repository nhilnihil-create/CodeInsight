#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
using Graph = vector<vector<int>>;
const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

// dp[r][c]: [r][c]への経路の数
vector<vector<ll>> dp(1010, vector<ll>(1010, 0));
vector<vector<char>> a(1010, vector<char>(1010));
int main()
{
    int H, W;
    cin >> H >> W;
    for (int row = 0; row < H; row++) {
        for (int col = 0; col < W; col++) {
            cin >> a[row][col];
        }
    }

    dp[0][0] = 1;

    for (int row = 0; row < H; row++) {
        for (int col = 0; col < W; col++) {
            if (a[row][col] == '#')
                continue;
            dp[row + 1][col] += dp[row][col];
            dp[row + 1][col] %= MOD;
            dp[row][col + 1] += dp[row][col];
            dp[row][col + 1] %= MOD;
        }
    }
    cout << dp[H - 1][W - 1] << endl;

    return 0;
}