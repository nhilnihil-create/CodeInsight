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
    lint N, Y;
    cin >> N >> Y;
    for (int a = 0; a <= N; a++) {
        for (int b = 0; b <= N - a; b++) {
            lint c = N - (a + b);
            if (10000 * a + 5000 * b + 1000 * c == Y) {
                cout << a << ' ' << b << ' ' << c << endl;
                return 0;
            }
        }
    }

    cout << -1 << ' ' << -1 << ' ' << -1 << endl;
    return 0;
}