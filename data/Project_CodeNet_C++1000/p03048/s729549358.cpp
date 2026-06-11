#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int R, G, B, n;
    cin >> R >> G >> B >> n;

    int ans = 0;
    for (int r = 0; r <= n / R; r++) {
        for (int g = 0; g <= n / G; g++) {
            int b = (n - r * R - g * G) / B;
            if (b < 0 || b > n / B) continue;
            if (R * r + G * g + B * b == n) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
