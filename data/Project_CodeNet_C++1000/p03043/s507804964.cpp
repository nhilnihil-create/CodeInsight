#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    double ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += pow(0.5, ceil(max(0.0, log2(1.0 * K / i)))) / N;
    }
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}
