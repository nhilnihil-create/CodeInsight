#include "bits/stdc++.h"

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> X(N);
    for (int i = 0; i < N; ++i)
        cin >> X[i];

    int ans = INT_MAX;
    for (int i = 0; i + K <= N; ++i) {
        int tmp = abs(X[i + K - 1] - X[i]) + min(abs(X[i]), abs(X[i + K - 1]));
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}