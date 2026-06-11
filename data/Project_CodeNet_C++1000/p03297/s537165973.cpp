#include <bits/stdc++.h>
//#include "atcoder/all"
typedef long long int ll;
using namespace std;
// using namespace atcoder;
ll gcd(ll x, ll y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if ((d < b) || (a < b)) {
            cout << "No" << endl;
        }
        else if (c >= b - 1) {
            cout << "Yes" << endl;
        }
        else {
            // c+1からb-1の間にa + k * gcd(b, d)なる数あったらNo
            ll e = gcd(b, d);
            if (b - 1 - c >= e) {
                cout << "No" << endl;
            }
            else if (((c + 1) % e <= a % e) && (a % e <= (b - 1) % e)) {
                cout << "No" << endl;
            }
            else if (((c + 1) % e > (b - 1) % e) && (((c + 1) % e <= a % e) || ((b - 1) % e >= a % e))) {
                cout << "No" << endl;
            }
            else {
                cout << "Yes" << endl;
            }
        }
    }
    return 0;
}