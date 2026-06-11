#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

ll ceil(ll a, ll b) {
    if (b < 0) {
        a *= -1;
        b *= -1;
    }
    if (a >= 0) {
        return (a + b - 1) / b;
    } else {
        return a / b;
    }
}

ll floor(ll a, ll b) {
    if (b < 0) {
        a *= -1;
        b *= -1;
    }
    if (a < 0) {
        return (a - b + 1) / b;
    } else {
        return a / b;
    }
}

int main() {
    int K;
    cin >> K;
    vector<ll> A(K + 1, 0);
    for (int i = 1; i <= K; i++) {
        cin >> A[i];
    }

    vector<ll> L(K + 1, 0), R(K + 1, 0);
    L[K] = 2;
    R[K] = 2;
    for (int i = K; i >= 1; i--) {
        if (!(L[i] % A[i] == 0 || L[i] / A[i] < R[i] / A[i])) {
            cout << -1 << endl;
            return 0;
        }
        L[i - 1] = ceil(L[i], A[i]) * A[i];
        R[i - 1] = floor(R[i], A[i]) * A[i] + A[i] - 1;
    }
    cout << L[0] << " " << R[0] << endl;
}
