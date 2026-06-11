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

vector<int> memo(1000000, -1);

int dfs(int N) {
    if (memo[N] != -1) return memo[N];

    int res = INF;
    res     = min(dfs(N - 1) + 1, res);

    for (int i = 1; pow(6, i) <= N; i++) {
        res = min(dfs(N - pow(6, i)) + 1, res);
    }
    for (int i = 1; pow(9, i) <= N; i++) {
        res = min(dfs(N - pow(9, i)) + 1, res);
    }

    return memo[N] = res;
}

int main() {
    int N;
    cin >> N;
    memo[0] = 0;
    cout << dfs(N) << endl;

    return 0;
}