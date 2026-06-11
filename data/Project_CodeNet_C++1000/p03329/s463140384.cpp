#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> P;

const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

const int MAX_N = 110000;

int dp[MAX_N]; // memo[i]がiについての答え

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < MAX_N; i++)
        dp[i] = N;
    dp[0] = 0;

    // 配るDP
    for (int n = 0; n <= N; n++) {
        for (int pow6 = 1; pow6 + n <= N; pow6 *= 6) {
            dp[n + pow6] = min(dp[n + pow6], dp[n] + 1);
        }
        for (int pow9 = 1; pow9 + n <= N; pow9 *= 9) {
            dp[n + pow9] = min(dp[n + pow9], dp[n] + 1);
        }
    }

    cout << dp[N] << endl;

    return 0;
}