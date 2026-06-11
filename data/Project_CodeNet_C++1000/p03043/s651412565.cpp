#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1 << 29;
const int MOD = 1000000007;

int main() {
    // 愚直に求める
    long long n, k;
    cin >> n >> k;

    double ans = 0.0;

    // 1 <= k <= nにおいてそれぞれ確率を求めて足す
    for (long long num = 1; num <= n; num++) {
        long long number = num;
        long long index = 0;
        // 2^i >= kとなるまでループする
        while (number < k) {
            index += 1;
            number *= 2;
        }

        double plus = 1.0 / (double)n * pow(0.5, index);
        ans += plus;
    }
    cout << fixed << setprecision(12) << ans << endl;
}
