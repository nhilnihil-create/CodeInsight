#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
#define INF __INT32_MAX__

void chmax(ll &x, ll y) { if (x < y) x = y; }

int main() {
    ll N, K;
    cin >> N >> K;
    vl A(N);
    rep(i, N) {
        cin >> A[i];
    }

    const int DIGIT_MAX = 50;

    vector<vector<ll>> dp(DIGIT_MAX + 1, vector<ll>(2, -1));
    dp[0][0] = 0;

    for (int d = 0; d < DIGIT_MAX; d++) {
        ll mask = 1LL<<(DIGIT_MAX - 1 - d);

        ll num = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] & mask) num++;
        }

        ll cost0 = mask * num;
        ll cost1 = mask * (N - num);

        if (dp[d][0] != -1) {
            if (K & mask) {
                chmax(dp[d + 1][0], dp[d][0] + cost1);
            } else {
                chmax(dp[d + 1][0], dp[d][0] + cost0);
            }
        }

        if (dp[d][0] != -1) {
            if (K & mask) {
                chmax(dp[d + 1][1], dp[d][0] + cost0);
            }
        }

        if (dp[d][1] != -1) {
            chmax(dp[d + 1][1], dp[d][1] + max(cost0, cost1));
        }
    }
    cout << max(dp[DIGIT_MAX][0], dp[DIGIT_MAX][1]) << endl;
}