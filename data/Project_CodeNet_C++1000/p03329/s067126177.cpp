#include <bits/stdc++.h>
using namespace std;

#define d(x) cerr << #x ":" << x << endl;
#define dd(x, y) cerr << "(" #x "," #y "):(" << x << "," << y << ")" << endl
#define rep(i, n) for (int i = (int)(0); i < (int)(n); i++)
#define repp(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define all(v) v.begin(), v.end()
#define dump(v)                  \
    cerr << #v ":[ ";            \
    for (auto macro_vi : v) {    \
        cerr << macro_vi << " "; \
    }                            \
    cerr << "]" << endl;
#define ddump(v)                           \
    cerr << #v ":" << endl;                \
    for (auto macro_row : v) {             \
        cerr << "[";                       \
        for (auto macro__vi : macro_row) { \
            cerr << macro__vi << " ";      \
        }                                  \
        cerr << "]" << endl;               \
    }
using lint       = long long;
const int INF    = 1e9;
const lint LINF  = 1e18;
const lint MOD   = 1e9 + 7;
const double EPS = 1e-10;

int main() {
    int N;
    cin >> N;

    vector<int> dp(N + 1, INF);
    dp[0] = 0;

    dp[0] = 0;
    for (int i = 0; i < N; i++) {

        dp[i + 1] = min(dp[i + 1], dp[i] + 1);

        for (int j = 1; i + pow(6, j) <= N; j++) {
            int plus     = pow(6, j);
            dp[i + plus] = min(dp[i + plus], dp[i] + 1);
        }

        for (int j = 1; i + pow(9, j) <= N; j++) {
            int plus     = pow(9, j);
            dp[i + plus] = min(dp[i + plus], dp[i] + 1);
        }
    }
    cout << dp[N] << endl;
    return 0;
}