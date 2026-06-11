#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        long long tmp = 0;
        tmp += (N / i) * max(i - K, 0);
        tmp += max(N % i - K + 1, 0);
        if (K == 0 && tmp > 1) tmp--;
        ans += tmp;
    }
    cout << ans << endl;
}