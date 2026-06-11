#include <bits/stdc++.h>
using namespace std;

#define d(x) cerr << #x ":" << x << endl;
#define dd(x, y) cerr << "(" #x "," #y "):(" << x << "," << y << ")" << endl
#define rep(i, n) for (int i = (int)(0); i < (int)(n); i++)
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
const double EPS = 1e-10;

int main() {
    lint N;
    cin >> N;

    vector<lint> divs(0);
    for (lint x = 1; x * x <= N; x++) {
        if (N % x == 0) {
            divs.push_back(x);
            if (x * x != N) divs.push_back(N / x);
        }
    }
    sort(divs.begin(), divs.end());
    // dump(divs);

    lint ans = 0;
    for (lint r : divs) {
        lint m = N / r - 1;
        if (r < m) ans += m;
    }

    cout << ans << endl;
    return 0;
}