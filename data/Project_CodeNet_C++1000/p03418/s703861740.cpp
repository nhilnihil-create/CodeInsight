#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int64_t N, K;
    cin >> N >> K;
    if(K == 0) {
        cout << N*N << endl;
    } else {
        int64_t ans = 0;
        for(int64_t b=K+1; b<=N; b++) {
            int64_t n = (N+1) / b;
            ans += n * (b-K);
            // cout << b << " " << n << " " << n*(b-K) << endl;
            ans += max(N - (n*b-1LL) - K, 0LL);
        }
        cout << ans << endl;
    }
    return 0;
}
