#include <iostream>
using namespace std;
int n;
long long a[404], b[404], d[404][404];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) b[i] = b[i - 1] + a[i];
    for (int i = 1; i < n; i++) for (int j = 1; j + i <= n; j++) {
        int l = j, r = j + i;
        d[l][r] = 1e18;
        for (int k = l; k < r; k++)
            d[l][r] = min(d[l][r], d[l][k] + d[k + 1][r] + b[r] - b[l - 1]);
    }
    cout << d[1][n] << '\n';
}