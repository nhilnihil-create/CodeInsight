#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main() {
    ll x;
    cin >> x;
    ll res = 1;
    for (ll i = 2; i * i <= x; ++i) {
        ll tmp = 1;
        ll y = x;
        while (y/i>0) {
            y /= i;
            tmp *= i;
            res = max(res, tmp);
        }
    }
    cout << res << endl;;
}
