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
    int N;
    cin >> N;
    vector<lint> A(N, 0);
    rep(i, N) cin >> A[i];

    vector<lint> L(N + 1, 0);
    rep(i, N) L[i + 1] = L[i] + A[i];

    // dump(A);
    // dump(L);

    map<lint, lint> mp;
    for (int i = 0; i <= N; i++) {
        mp[L[i]]++;
    }

    lint cnt = 0;
    for (auto p : mp) {
        lint x, c;
        tie(x, c) = p;
        dd(x, c);
        cnt += c * (c - 1) / 2;
    }

    cout << cnt << endl;
    return 0;
}