// 7/15
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    string S;
    cin >> N >> S;

    vector<int> L(N + 1);  // i番目まででWを向いている人数。
    vector<int> R(N + 1);  // i番目〜N-1番目まででEを向いている人数。

    L[0] = 0;
    R[N] = 0;

    rep(i, N) {
        if (S[i] == 'W') L[i+1] = L[i] + 1;
        else L[i+1] = L[i];
    }
    // R[N+1] = R[N];

    for (int i = N-1; i >= 0; i--) {
        if (S[i] == 'E') R[i] = R[i + 1] + 1;
        else R[i] = R[i + 1];
    }

    // cout << "L: ";
    // rep(i, N+1) {
    //     cout << L[i] << " ";
    // }
    // cout << endl;
    // cout << "R: ";
    // rep(i, N+1) {
    //     cout << R[i] << " ";
    // }
    // cout << endl;

    int res = N;
    rep(i, N) {
        res = min(res, L[i] + R[i+1]);
    }

    cout << res << endl;
    return 0;
}