#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll N, K;
    cin >> N >> K;
    if (K == 0) {
        cout << N * N << "\n";
        return 0; 
    }
    ll ans = 0;
    for (int b = K + 1; b <= N; b++) {
        int n = (N+1) / b;
        ans += n * (b - K) + max(0ll, N - ( n * b + K) + 1);
        //printf("%d %d %d\n", b, n, N - (n * b + K));
    }
    cout << ans << "\n";
    return 0;
}