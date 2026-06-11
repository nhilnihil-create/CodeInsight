#include "bits/stdc++.h"

using namespace std;

int main() {
    int N, D, X;
    cin >> N >> D >> X;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    int ans = X;
    for (int i = 0; i < N; ++i) {
        // A_i * x + 1 <= D
        ans += (D - 1) / A[i] + 1;
    }
    cout << ans << endl;
}
