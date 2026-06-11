#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    if (!K) return cout << (long)N * N << "\n", 0;
    
    long ans = 0;
    for (int b = K + 1; b <= N; b++) {
        ans += (b - K) * (N / b);
        ans += max(0, N % b - K + 1);
    }
    
    cout << ans << "\n";
}