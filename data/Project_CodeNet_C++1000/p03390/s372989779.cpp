#include <iostream>
using namespace std;
typedef long long ll;

ll sqrtll(ll p) {
    ll ok = 0, ng = (1LL << 31);
    while (ng - ok > 1) {
        ll mid = (ok + ng) / 2;
        if (mid * mid < p) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    return ok;
}

int main() {
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; ++q) {
        ll A, B;
        cin >> A >> B;
        if (A >= B) {
            swap(A, B);
        }  // A < B

        if (B - A <= 1) {
            cout << (A - 1) * 2 << endl;
        } else {
            ll C = sqrtll(A * B);
            if (C * (C + 1) >= A * B) {
                cout << 2 * C - 2 << endl;
            } else {
                cout << 2 * C - 1 << endl;
            }
        }
    }
    return 0;
}
