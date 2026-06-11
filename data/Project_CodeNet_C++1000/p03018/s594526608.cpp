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
    string S;
    cin >> S;
    int N = S.size();

    lint cost = 0;

    lint ans = 0;
    for (int i = 0; i < N;) {
        if (S[i] == 'A') {
            cost++;
            i += 1;
        } else if (S.substr(i, 2) == "BC") {
            ans += cost;
            i += 2;
        } else {
            i += 1;
            cost = 0;
        }
    }

    cout << ans << endl;

    return 0;
}