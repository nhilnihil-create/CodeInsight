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
    vector<ll> A(K);
    for (int i = 0; i < K; i++) {
        cin >> A[i];
    }

    vector<ll> M(K + 1), m(K + 1);
    M[K] = 2;
    m[K] = 2;
    for (int i = K - 1; i >= 0; i--) {
        if (m[i + 1] / A[i] == M[i + 1] / A[i] && m[i + 1] % A[i] != 0 && M[i + 1] % A[i] != 0) {
            cout << -1 << endl;
            return 0;
        }
        m[i] = ceil(m[i + 1], A[i]) * A[i];
        M[i] = floor(M[i + 1], A[i]) * A[i] + A[i] - 1;
    }
    cout << m[0] << " " << M[0] << endl;
}
