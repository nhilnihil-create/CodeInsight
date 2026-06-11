#include <bits/stdc++.h>
using namespace std;

#define REP(i, start, count) for(int i=(start); i<(int)(count); ++i)
#define rep(i, count) REP(i, 0, count)
#define ALLOF(c) (c).begin(), (c).end()

using ll = long long;
using ull = unsigned long long;
using veci = vector<int>;
using vecll = vector<ll>;
using vecull = vector<ull>;

constexpr ll INF = 1LL << 60;

int main(void) {
    ll N;
    cin >> N;

    // dp[i]: i円を引き出すために必要な最小の回数
    vecll dp(N + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < N; ++i) {
        dp[i + 1] = min(dp[i + 1], dp[i] + 1);

        ll n = 6;
        while (i + n <= N) {
            dp[i + n] = min(dp[i + n], dp[i] + 1);
            n *= 6;
        }

        n = 9;
        while (i + n <= N) {
            dp[i + n] = min(dp[i + n], dp[i] + 1);
            n *= 9;
        }
    }

    cout << dp[N] << endl;
    return 0;
}
