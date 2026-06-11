#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int>A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < N; ++i) {
        if (A[i] > i) {
            cout << -1 << "\n";
            return 0;
        }
    }

    ll ans = A.back();
    for (int i = N - 1; i > 0; --i) {
        if (A[i] - 1 > A[i-1]) {
            cout << -1 << "\n";
            return 0;
        } else if (A[i] - 1 == A[i-1]) {
            continue;
        } else {
            ans += A[i-1];
        }
    }
    cout << ans << "\n";
    return 0;
}