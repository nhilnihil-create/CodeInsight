#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

constexpr ld eps = 1e-18;

int main() {
    ll k; cin >> k;
    auto calc = [] (ll x) {
        ll tx = x, sum = 0;
        while(x > 0) {
            sum += x % 10;
            x /= 10;
        }
        return (ld) tx / sum;
    };
    auto f = [&calc] (ll x) {
        int d = 0;
        {
            auto tx = x;
            while(tx > 0) tx /= 10, d += 1;
        }
        ll y = 10;
        ll res = x;
        for(int i = 0; i < d; ++i) {
            const auto z = y * (x / y + 1) - 1;
            if(z <= x) continue;
            if(fabs(calc(res) - calc(z)) < eps) {
                res = min(res, z);
            } else if(calc(res) > calc(z)) {
                res = z;
            }
            y *= 10;
        }
        return res;
    };

    ll x = 1;
    for(int i = 0; i < k; ++i) {
        cout << x << endl;
        x = f(x + 1);
    }
}
