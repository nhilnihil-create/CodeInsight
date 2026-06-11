#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N, K;
    cin >> N >> K;
    vector<int> h(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> h[i];
    }

    sort(h.begin(), h.end());

    int ans = h[N - 1] - h[0] + 100;
    for (int i = 0; i < N - K + 1; ++i) {
        ans = min(ans, h[i + K - 1] - h[i]);
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
