#include <iostream>
using namespace std;
int main() {
    int n, X; cin >> n >> X;
    int x[n]; for (int i = 0; i < n; i++) cin >> x[i];
    unsigned long long s[n+1];
    s[0] = 0; for (int i = 0; i < n; i++) s[i+1] = s[i] + x[i];
    unsigned long long ans;
    for (int m = 1; m <= n; m++) {
        unsigned long long sum = (unsigned long long)(m + n) * X;
        sum += 5 * (s[n] - s[max(0, n-2*m)]);
        for (int c = 7, i = n-2*m; i > 0; c += 2, i -= m) {
            sum += c * (s[i] - s[max(0, i-m)]);
        }
        if (m == 1 || sum < ans) ans = sum;
    }
    cout << ans << endl;
}
