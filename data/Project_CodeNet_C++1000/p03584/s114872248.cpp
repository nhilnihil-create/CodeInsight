#include"bits/stdc++.h"
using namespace std;

int main() {
    int64_t N, K;
    cin >> N >> K;
    vector<int64_t> A(N), B(N);
    for (int64_t i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    int64_t ans = 0;
    for (int64_t i = 0; i < N; i++) {
        if ((A[i] | K) == K) {
            ans += B[i];
        }
    }

    for (int64_t i = 0; i < 30; i++) {
        //i - 1桁目までどうでもよく、j桁目が1ではなく0で、i + 1桁目以降は同一
        if ((K & (1LL << i)) == 0) {
            continue;
        }

        int64_t Ki = K;
        Ki ^= (1LL << i);
        for (int64_t j = 0; j < i; j++) {
            Ki |= (1LL << j);
        }

        int64_t curr = 0;
        for (int64_t j = 0; j < N; j++) {
            if ((A[j] | Ki) == Ki) {
                curr += B[j];
            }
        }
        ans = max(ans, curr);
    }

    cout << ans << endl;
}