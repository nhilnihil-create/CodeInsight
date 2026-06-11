#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)

template <class T>
inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

ll const INF = 1LL << 60;
ll const MAX_N = 100000;
ll const MOD = 1000000007;

// 桁DPの遷移
// - 2進数の計算

// N=63435 について、
// dp[3][true]  : 634○○未満となる数(00000 - 63399)についての暫定の答え
// dp[3][false] : 634○○ となる数(63400 ~ 63429)についての暫定の答え

// dp[i][true] から dp[i+1][true]にのみ遷移
// (i桁目まででNより小さいなら、i+1桁目をどのように選んでもNより小さい）
// dp[i][false] から dp[i+1][true]へ遷移
// (i桁目までNと同じで、 i+1桁目はNより小さい数の時)
// dp[i][false] から dp[i+1][false]へ遷移
// (i桁目までNと同じで、 i+1桁目もNと同じ数の時)

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    const int MAX_BIT = 45;
    ll dp[MAX_BIT + 1][2];

    rep(i, MAX_BIT + 1) rep(j, 2) dp[i][j] = -1;

    dp[MAX_BIT][0] = 0;

    for (int d = MAX_BIT - 1; d >= 0; d--) {
        ll mask = 1LL << d;
        ll num = 0;

        rep(i, N) {
            if (A[i] & mask) num++;
        }

        // cout << "dp[" << d + 1 << "][0]: " << dp[d + 1][0] << ", "
        //      << "dp[" << d + 1 << "][1]: " << dp[d + 1][1] << endl;
        // cout << "- mask: " << mask << endl;
        // cout << "- 0:" << N - num << ", 1:" << num << endl;
        // cout << "- mask * num: " << mask * num << endl;
        // cout << "- mask * (N - num): " << mask * (N - num) << endl;

        if (dp[d + 1][1] >= 0) {
            dp[d][1] = dp[d + 1][1] + mask * max(num, N - num);
        }

        if (dp[d + 1][0] >= 0) {
            if (K & mask) {
                chmax(dp[d][1], dp[d + 1][0] + mask * num);
                dp[d][0] = dp[d + 1][0] + mask * (N - num);
            } else {
                dp[d][0] = dp[d + 1][0] + mask * num;
            }
        }
    }

    // rep(i, MAX_BIT + 1) {
    //     rep(j, 2) cout << dp[i][j] << " ";
    //     cout << endl;
    // }

    cout << max(dp[0][0], dp[0][1]) << endl;

    return 0;
}
