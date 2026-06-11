#include <iostream>
using namespace std;

int main() {
    long long N, K;
    cin >> N >> K;

    if (K == 0) {
        cout << N * N << endl;
        return 0;
    }

    long long res = 0;
    for (long long b = 1; b <= N; b++) {
        res += max(0LL, b - K) * (N / b);
        res += max(0LL, N % b - K + 1);
    }

    cout << res << endl;
    return 0;
}