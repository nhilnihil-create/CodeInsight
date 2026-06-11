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
    lint N, M;
    cin >> N >> M;

    vector<lint> divs(0);
    for (int i = 1; i * i <= M; i++) {
        if (M % i == 0) {
            divs.push_back(i);
            if (i * i != M) divs.push_back(M / i);
        }
    }
    sort(all(divs));
    // dump(divs);

    lint ans = -1;
    for (lint i = 0; i < divs.size(); i++) {
        // d(i);
        // d(M / divs[i]);
        if (N <= M / divs[i]) ans = max(ans, divs[i]);
    }
    cout << ans << endl;

    return 0;
}