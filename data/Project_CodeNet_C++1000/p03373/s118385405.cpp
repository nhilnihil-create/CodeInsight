#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int ans = 0;
    int money = (a + b) * (min(x, y));
    for (int i = 1; i <= min(x, y); i++) {
        money = min(money, 2 * c * i + (a + b) * (min(x, y) - i));
    }
    ans += money;

    money = 2 * c * abs(x - y);
    if (x >= y) {
        for (int i = 1; i <= x - y; i++) {
            money = min(money, 2 * c * (x - y - i) + a * i);
        }
    } else {
        for (int i = 1; i <= y - x; i++) {
            money = min(money, 2 * c * (y - x - i) + b * i);
        }
    }
    ans += money;

    cout << ans << endl;
}