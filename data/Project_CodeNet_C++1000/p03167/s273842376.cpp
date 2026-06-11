




#include <bits/stdc++.h>
#define int long long
#define ld long double
#define f(a, b) for (ll i = a; i <= b; i++)
#define pb push_back
#define pf push_front
#define mp make_pair
using namespace std;
#define N 200005
const int INF = 1000000001;
const int MOD = 1000000007;
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int dp[1001][1001] = {0};
int ways(int h, int w) {
    //int dp[1001][1001]={0};
    if (dp[0][0] == -1) {
        return 0;
    }
    for (int j = 0; j < w; j++) {
        if (dp[0][j] == -1) {
            break;
        }
        dp[0][j] = 1;
    }
    for (int i = 0; i < h; i++) {
        if (dp[i][0] == -1) {
            break;
        }
        dp[i][0] = 1;
    }
    for (int i = 1; i < h; i++) {
        for (int j = 1; j < w; j++) {
            if (dp[i][j] == -1)
                continue;
            dp[i][j] = 0;
            if (dp[i][j - 1] != -1)
                dp[i][j] = dp[i][j - 1] % MOD;;
            if (dp[i - 1][j] != -1) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;;
            }
        }
    }
    if (dp[h - 1][w - 1] == -1)
        return 0;

    return dp[h - 1][w - 1];


}
int32_t main() {
    c_p_c();
    memset(dp, 0, sizeof dp);

    int h, w;
    cin >> h >> w;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char no;
            cin >> no;
            if (no == '#') {
                dp[i][j] = -1;
            }
        }

    }
    cout << ways(h, w);
}
