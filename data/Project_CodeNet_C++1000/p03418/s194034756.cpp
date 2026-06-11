#include "bits/stdc++.h"

using namespace std;

void Main() {
    long long N, K;
    cin >> N >> K;

    if (K == 0) {
        cout << N * N << endl;
        return;
    }
    long long ans = 0;
    for (long long b = K + 1; b <= N; ++b) {
        ans += (b - K) * (N / b);
        if (N % b != 0) {
            long long begin = b * (N / b) + K;
            long long end = N + 1;
            ans += max(0LL, end - begin);
        }
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
