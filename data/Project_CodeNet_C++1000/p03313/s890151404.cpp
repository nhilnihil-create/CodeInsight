#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) for (int i=0;i<(n);++i)

using namespace std;

template <class T, class U> void amax(T& x, U y) {if (x < y) x = y;}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> A(1 << N);
    REP(i, A.size()) {
        cin >> A[i];
    }

    vector<int> dp(1 << N);
    vector<int> B(1 << N);
    B[0] = A[0];
    vector<vector<int>> C(1 << N, vector<int>(N, -1));
    FOR(i, 1, 1 << N) {
        B[i] = A[i];
        dp[i] = dp[i - 1];
        REP(j, N) {
            if (i & (1 << j)) {
                amax(B[i], B[i ^ (1 << j)]);
                C[i][j] = A[i];
                REP(k, N) {
                    if (k == j) continue;
                    if (i & (1 << k)) {
                        amax(C[i][j], C[i ^ (1 << k)][j]);
                    }
                }
                amax(dp[i], B[i ^ (1 << j)] + C[i][j]);
            }
        }
        cout << dp[i] << '\n';
    }
    cout << flush;

    return 0;
}
