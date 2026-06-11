#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
// Welcome to my source code!

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll price = 0, t;
    if (a + b >= 2 * c) {
        int maxq = max(x, y);
        int minq = min(x, y);
        if (maxq == x) t = a;
        else t = b;
        price += 2 * c * minq;
        maxq -= minq;
        minq = 0;
        if (maxq && t >= 2 * c) {
            price += 2 * c * maxq;
        } else if (maxq) {
            price += maxq * t;
        }
    } else {
        price = x * a + y * b;
    }
    cout << price << endl;
}