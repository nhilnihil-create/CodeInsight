#include "bits/stdc++.h"

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    // 3 ^ n - odd
    int X = 1, Y = 1;
    for (int i = 0; i < N; ++i) {
        X *= 3;
        if ((A[i] & 1) == 0) Y *= 2;
    }
    cout << X - Y << endl;
}