#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

template<class T> inline bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }

int main() {
    int N; cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    rep(i, N) rep(j, N) cin >> A[i][j];
    vector<int64_t> score(1 << N), dp(1 << N);
    rep(oi, 1 << N) {
        bitset<22> OI(oi);
        rep(i, N) rep(j, N) if(OI[i] && OI[j]) score[oi] += A[i][j];
        score[oi] /= 2;
        for(int sub = oi; sub > 0; sub = (sub - 1) & oi) {
            chmax(dp[oi], dp[oi ^ sub] + score[sub]);
        }
    }
    cout << dp[(1 << N) - 1] << '\n';
}
