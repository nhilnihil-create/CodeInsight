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
    string S;
    cin >> S;
    int N    = S.size();
    int head = 0, tale = N;

    int ans = 0;
    while (head < tale) {
        if (S[head] == S[tale - 1])
            head++, tale--;
        else {
            if (S[head] == 'x') {
                ans++;
                head++;
            } else if (S[tale - 1] == 'x') {
                ans++;
                tale--;
            } else {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}