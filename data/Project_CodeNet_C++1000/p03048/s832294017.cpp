#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int r, g, b, n;
    cin >> r >> g >> b >> n;
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            int residual = n - r * i - g * j;
            if (residual < 0) continue;
            if (residual % b == 0) ans++;
        }
    }
    cout << ans << endl;
}