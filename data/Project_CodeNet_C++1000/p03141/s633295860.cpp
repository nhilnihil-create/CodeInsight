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

struct data {
    int a, b, sum;
};

bool comp(const data &a, const data &b) {
    if (a.sum > b.sum) {
        return true;
    } else {
        return false;
    }
    return 0;
}

int main() {
    int N;
    cin >> N;
    vector<data> A(N);
    rep(i, N) {
        cin >> A[i].a >> A[i].b;
        A[i].sum = A[i].a + A[i].b;
    }
    sort(all(A), comp);

    lint ans = 0;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            ans += A[i].a;
        } else {
            ans -= A[i].b;
        }
    }
    cout << ans << endl;
    return 0;
}