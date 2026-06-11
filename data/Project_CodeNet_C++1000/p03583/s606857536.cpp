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
    for (int n = 1; n <= 3500; n++) {
        for (int w = 1; w <= 3500; w++) {
            lint a = 4 * n * w - (w + n) * N;
            if (a <= 0) continue;

            lint b = n * w * N;
            if (b % a != 0) continue;
            cout << n << ' ' << w << ' ' << (b / a) << endl;
            return 0;
        }
    }

    return 0;
}