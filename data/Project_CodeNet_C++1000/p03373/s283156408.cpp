#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans = 0;
    if (a + b <= 2 * c) {
        ans = a * x + b * y;
    }
    else {
        if (x >= y) {
            ans = min(2*c*x, 2*c*y+(x-y)*a);
        }
        else {
            ans = min(2*c*y, 2*c*x+(y-x)*b);
        }
    }
    cout << ans << endl;
    return 0;
}
