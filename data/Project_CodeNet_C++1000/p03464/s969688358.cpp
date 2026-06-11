#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

int main() {
    int K;
    cin >> K;
    vector<ll> A(K + 1, 1), B(K + 1), C(K + 1);
    rep(i, K) cin >> A[i + 1];
    B[K] = A[K];
    C[K] = A[K];
    if (A[K] != 2) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = K - 1; i >= 0; i--) {
        B[i] = (B[i + 1] + A[i] - 1) / A[i] * A[i];
        C[i] = (C[i + 1] + A[i + 1] - 1) / A[i] * A[i];
        //cout << i << " " << B[i] << " " << C[i] << endl;
        if (B[i] > C[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << B[0] << " " << C[0] << endl;
}