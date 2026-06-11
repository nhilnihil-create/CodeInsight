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

lint xor_(lint X) {
    lint ans = 0;
    for (lint d = 0; d < 60; d++) {
        lint T   = (1ll << d) * 2;
        lint cnt = ((X + 1) / T) * T / 2 + max(0ll, ((X + 1) % T) - T / 2);
        cnt %= 2;
        ans += (1ll << d) * cnt;
    }
    return ans;
}

int main() {
    lint A, B;
    cin >> A >> B;
    cout << (xor_(B) ^ xor_(A - 1)) << endl;
    return 0;
}