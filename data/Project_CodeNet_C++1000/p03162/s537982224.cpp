#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
// using Graph = vector<vector<Edge>>;
const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

// 配るdp
int main()
{
    int N;
    cin >> N;
    vector<int> a(N + 5);
    vector<int> b(N + 5);
    vector<int> c(N + 5);

    vector<vector<int>> dp(N + 5, vector<int>(3, 0));

    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];

    for (int i = 0; i < N - 1; i++) {
        dp[i + 1][0] = max(dp[i + 1][0], dp[i][1] + a[i + 1]);
        dp[i + 1][0] = max(dp[i + 1][0], dp[i][2] + a[i + 1]);

        dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] + b[i + 1]);
        dp[i + 1][1] = max(dp[i + 1][1], dp[i][2] + b[i + 1]);

        dp[i + 1][2] = max(dp[i + 1][2], dp[i][0] + c[i + 1]);
        dp[i + 1][2] = max(dp[i + 1][2], dp[i][1] + c[i + 1]);
    }

    int res = max({ dp[N - 1][0], dp[N - 1][1], dp[N - 1][2] });
    cout << res << endl;

    return 0;
}