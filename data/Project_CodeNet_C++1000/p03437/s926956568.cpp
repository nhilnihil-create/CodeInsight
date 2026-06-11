#include <iostream>

using namespace std;
typedef long long ll;

int main() {
    ll x, y;
    cin >> x >> y;

    if (x % y == 0ll) {
        cout << -1 << endl;
    } else {
        for (ll i = 2ll; x * i < 1000000000000000000ll; i++) {
            if (x * i % y != 0) {
                cout << x * i << endl;
                return 0;
            }
        }
    }
}