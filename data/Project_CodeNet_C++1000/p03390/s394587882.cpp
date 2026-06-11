#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        if (a == b) {
            cout << 2 * a - 2 << endl;
            continue;
        }
        ll l = 0, r = 1000000000;
        while (l < r) {
            ll m = (l + r + 1) / 2;
            if (m * m >= a * b) {
                r = m - 1;
            } else {
                l = m;
            }
        }
        if (l * (l + 1) < a * b) {
            cout << 2 * l - 1 << endl;
        } else {
            cout << 2 * l - 2 << endl;
        }
    }
}
