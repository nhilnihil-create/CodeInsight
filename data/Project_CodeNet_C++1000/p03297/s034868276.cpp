#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int T; cin >> T;
    while(T--) {
        ll a, b, c, d; cin >> a >> b >> c >> d;
        //cout << "a, b, c, d: " << a << " " << b << " " << c << " " << d << endl;
        if(a < b || d < b) {
            cout << "No" << endl;
        } else if(c >= b) {
            cout << "Yes" << endl;
        } else {
            if(a >= c + 1) {
                const ll t = a - (a - c - 1) / b * b;
                if(c < t && t < b) {
                    cout << "No" << endl;
                    continue;
                }
            }
            const ll g = __gcd(b, d);
            ll t = (a < c ? a - b : a - (a - c + b - 1) / b * b);
            t += (c + 1 - t + g - 1) / g * g;
            //cout << "t: "<< t << endl;
            if(c < t && t < b) {
                cout << "No" << endl;
            } else {
                cout << "Yes" << endl;
            }
        }
    }
}