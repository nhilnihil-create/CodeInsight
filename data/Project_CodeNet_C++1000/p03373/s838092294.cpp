#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <utility>
#include <algorithm>

using namespace std;
using ll = long long;

#define FOR(i, a, b) for (int i = a; i < (b); i++)

int main() {
    ll a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    if (x > y) {
        swap(a, b);
        swap(x, y);
    }
    // cout << a << b << c << x << y;
    ll cost = 0;
    if (a + b > 2 * c) {
        if (b > 2 * c) {
            cost += 2 * y * c;
        } else {
            cost += 2 * x * c + (y - x) * b;
        }
    } else {
        cost += x * a + y * b;
    }
    cout << cost << endl;
    return 0;
}
