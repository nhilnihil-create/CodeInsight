#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cassert>
#include <set>
#include <numeric>

using namespace std;

using ll = long long;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        if (a < b || d < b) {
            cout << "No" << endl;
            continue;
        }

        if (a > c) {
            a = a - b * ((a - c + b - 1) / b);

            if (a < 0) {
                cout << "No" << endl;
                continue;
            }
        } 

        a += d;

        ll e = d - b;

        if (e == 0) {
            cout << "Yes" << endl;
            continue;
        }

        ll t = (-b + (b + e - 1) / e * e) % (d - b);
        ll s = __gcd(t, e);

        ll ng_l = c + b + 1;
        ll ng_r = min(2 * b - 1, c + d);

        if (ng_r - ng_l + 1 <= 0) {
            cout << "Yes" << endl;
            continue;
        }
        
        if (ng_r - ng_l + 1 >= s) {
            cout << "No" << endl;
            continue;
        }

        if (ng_l % s <= ng_r % s) {
            if (ng_l % s <= a % s && a % s <= ng_r % s) {
                cout << "No" << endl;
                continue;
            }
        } else {
            if (ng_l % s <= a % s || a % s <= ng_r % s) {
                cout << "No" << endl;
                continue;
            }
        }

        cout << "Yes" << endl;
    }
}

