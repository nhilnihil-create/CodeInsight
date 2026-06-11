#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int i = 1; i * i <= m; i++) {
        if (m % i == 0) {
            if (n <= i) ans = max(ans, m / i);
            if (n <= m / i) ans = max(ans, i);
        }
    }
    cout << ans << '\n';
}
