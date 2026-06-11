#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll S(ll x) {
    ll res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

ll f(ll x) {
    auto v = vector<ll>();
    for (ll d = 1; d <= x; d *= 10) {
        v.push_back((x / d + 1) * d - 1);
    }
    sort(begin(v), end(v));

    ll n = v[0];
    for (auto&& m : v) {
        if (S(n) * m <= S(m) * n) {
            n = m;
        }
    }
    return n;
}

int main() {
    int K;
    cin >> K;

    ll n = 0;
    while (K--) {
        n = f(n + 1);
        cout << n << endl;
    }
    return 0;
}
