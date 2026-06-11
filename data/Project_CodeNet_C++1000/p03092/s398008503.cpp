#ifndef __cplusplus
    cat << EOF
#endif
#include <bits/stdc++.h>
using namespace std;

#define rep(...) overload_rep(__VA_ARGS__, rep_1, rep_0)(__VA_ARGS__)
#define rep_0(i, end) for(int i = 0; i < (end); ++i)
#define rep_1(i, fr, ba) for(int i = (fr); i <= (ba); ++i)
#define overload_rep(arg0, arg1, arg2, name, ...) name
#define all(box) box.begin(), box.end()

template <class T, class U> inline bool chmax(T& lhs, const U& rhs) { if(lhs < rhs) { lhs = rhs; return 1; } return 0; }
template <class T, class U> inline bool chmin(T& lhs, const U& rhs) { if(lhs > rhs) { lhs = rhs; return 1; } return 0; }

typedef long long lint;
constexpr lint inf = (1ll << 60);

int N, X, Y;
int A[5000];
lint dp[5001][5001];

int main() {

    cin >> N >> X >> Y;
    rep(i, N) cin >> A[i];

    rep(i, 1, N) rep(j, 0, N) dp[i][j] = inf;

    rep(i, N) {
        rep(j, 0, N) {
            if(j < A[i]) {
                chmin(dp[i + 1][j], dp[i][j] + X);
                chmin(dp[i + 1][A[i]], dp[i][j]);
            }
            if(j > A[i]) {
                chmin(dp[i + 1][j], dp[i][j] + Y);
            }
        }
    }

    lint ans = inf;
    rep(i, 0, N) chmin(ans, dp[N][i]);
    cout << ans << '\n';

}
