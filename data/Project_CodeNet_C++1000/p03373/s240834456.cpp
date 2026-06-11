#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int ans;
    if (a + b > c * 2) {
        if (x > y) {
            int tmp = c * x * 2;
            ans = c * y * 2 + a * (x-y);
            ans = min(tmp, ans);
        }
        else {
            int tmp = c * y * 2;
            ans = c * x * 2 + b * (y-x);
            ans = min(tmp, ans);
        }
    }
    else {
        ans = a * x + b * y;
    }
    cout << ans << endl;
}
