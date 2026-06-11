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
    lint N;
    cin >> N;
    for (int h = 1; h <= 3500; h++) {
        for (int n = 1; n <= 3500; n++) {
            lint par, chi;
            par = N * h * n;
            chi = 4 * h * n - N * (n + h);
            if (chi == 0) continue;
            if (par % chi == 0) {
                lint w = par / chi;
                if (w >= 1) {
                    cout << h << " " << n << " " << w << endl;
                    return 0;
                }
            } else {
                continue;
            }
        }
    }
    return 0;
}