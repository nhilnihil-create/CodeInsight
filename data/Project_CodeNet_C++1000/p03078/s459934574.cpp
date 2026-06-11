// https://atcoder.jp/contests/abc123/tasks/abc123_d
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
#define DIV(a, b) ((a - 1) / b + 1)

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int X, Y, Z, K;
    cin >> X >> Y >> Z >> K;
    vector<int> A(X), B(Y), C(Z);
    for (auto &x : A)
        cin >> x;
    for (auto &x : B)
        cin >> x;
    for (auto &x : C)
        cin >> x;
    sort(ALLR(A));
    sort(ALLR(B));
    sort(ALLR(C));
    vector<int> ans;
    for (int a = 0; a < X; a++) {
        for (int b = 0; b < Y && (a + 1) * (b + 1) <= K; b++) {
            for (int c = 0; c < Z && (a + 1) * (b + 1) * (c + 1) <= K; c++) {
                ans.emplace_back(A[a] + B[b] + C[c]);
            }
        }
    }
    sort(ALLR(ans));
    REP(i, K) { cout << ans[i] << "\n"; }

    return 0;
}
