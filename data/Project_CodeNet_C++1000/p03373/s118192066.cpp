#include <bits/stdc++.h>
using namespace std;

int main() {
    int a , b , c , x ,y;
    cin >> a >> b >> c >> x >> y;
    
    int ans;
    ans = x * a + y * b;
    ans = min(2 * c *max(x, y), ans);
    if (x >= y) {
        ans = min(ans, 2 * c * y + a * (x - y));
    }
    else {
        ans = min(ans, 2 * c * x + b * (y - x));
    }

    cout << ans << endl;
    return 0;
}