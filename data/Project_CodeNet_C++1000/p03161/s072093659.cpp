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
    int N, K;
    cin >> N >> K;
    vector<int> h(N + 200);
    vector<int> dp(N + 200, INF_32);

    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    dp[0] = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = 1; j <= K; j++) {
            dp[i + j] = min(dp[i + j], dp[i] + abs(h[i + j] - h[i]));
        }
    }

    cout << dp[N - 1] << endl;

    return 0;
}