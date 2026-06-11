#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int64_t ans = 0;
    for (int b = 1; b < n+1; b++) {
        int p = n / b;
        int r = n % b;
        ans += p * max(0, b - k);
        ans += max(0, r - k + 1);
    }
    if (k == 0) ans -= n;
    cout << ans << endl;
}