#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll k, a, b;
    cin >> k >> a >> b;
    ll step = 0;
    ll biscuits = 1;
    ll money = 0;
    if (b - a > 1) {
        if (a > k + 1) {
            biscuits = k + 1;
        }
        else {
            step += a - 1;
            // a, bの順で繰り返す
            ll possible = (k - step) / 2;
            biscuits = a + possible * (b - a);
            step += 2 * possible;
            biscuits += (k - step);
        }
    }
    else {
        biscuits = k + 1;
    }
    cout << biscuits << endl;
}
