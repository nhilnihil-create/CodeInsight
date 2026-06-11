#include "bits/stdc++.h"

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> B(N), ans(N);
    for (int i = 0; i < N; ++i) cin >> B[i];

    bool ok = true;
    for (int n = N - 1; n >= 0; --n) {
        ans[n] = 0;
        for (int i = B.size() - 1; i >= 0; --i) {
            // cout << n << ' ' << B[i] << endl;
            if (B[i] == i + 1) {
                B.erase(B.begin() + i);
                ans[n] = max(ans[n], i + 1);
                break;
            }
            if (B[i] > i + 1) {
                ok = false;
                break;
            }
        }
        if (!ok)
            break;
    }

    if (ok) {
        for (int i = 0; i < N; ++i)
            cout << ans[i] << endl;
    } else {
        cout << -1 << endl;
    }
}