#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 基本戦略としてはそれぞれのコンテストでsqrt(A*B)位以内に入っている人間を全採用

int main() {
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; ++q) {
        ll A, B;
        cin >> A >> B;
        if (A > B) {
            ll temp = A;
            A = B;
            B = temp;
        }
        if (A == B || A+1 == B) {
            cout << A+A-2 << "\n";
            continue;
        }
        ll sq = (ll)(sqrt(A*B)-0.001);
        ll ans = 2 * sq - 1;
        if (sq*(sq+1) >= A*B) ans--;
        cout << ans << "\n";
    }
    return 0;
}