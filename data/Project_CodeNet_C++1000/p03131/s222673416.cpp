#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    ll k, a, b;
    cin >> k >> a >> b;

    ll ret = k + 1;
    ll c = k - (a - 1);
    if (b - a > 0 && c > 0) {
        ll x = a + (b - a) * (c / 2);
        if (c % 2 == 1)x++;
        ret = max(ret, x);
    }

    cout << ret << endl;
    return 0;
}