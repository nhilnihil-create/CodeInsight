#include <bits/stdc++.h>
using namespace std;

int main() {
    long long  n, k;
    cin >> n >> k;
    long long ans = 0;
    for (long long b = k + 1; b <= n; b++) {
        ans += (n / b) * (b - k);
        if (n % b >= k) ans += n % b - k + 1;
    }
    if (k == 0) ans = n * n;
    cout << ans << endl;
    return 0;
}