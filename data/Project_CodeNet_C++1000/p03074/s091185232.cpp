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
    lint N, K;
    string S;
    cin >> N >> K >> S;
    N = S.size();
    vector<lint> A(0);

    lint cnt = 1;

    if (S[0] == '0') { A.push_back(0); }

    for (int i = 0; i < N - 1; i++) {
        if (S[i + 1] == S[i]) {
            cnt++;
        } else {
            A.push_back(cnt);
            cnt = 1;
        }
    }
    A.push_back(cnt);

    // dump(A);

    vector<lint> L(A.size() + 1);
    rep(i, A.size()) L[i + 1] = L[i] + A[i];

    lint ans = -1;
    for (int left = 0; left < (lint)A.size(); left += 2) {
        int right = min(left + 2 * K + 1, (lint)A.size());
        ans       = max(ans, L[right] - L[left]);
    }

    cout << ans << endl;
    return 0;
}