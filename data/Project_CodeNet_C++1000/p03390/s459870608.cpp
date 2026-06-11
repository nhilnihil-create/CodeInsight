#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;

template <class T, class F>
T UpperBound(T i0, T i1, F f) {
    while (i0 < i1) {
        T i = i0 + (i1 - i0) / 2;
        if (f(i)) i0 = i + 1; else i1 = i;
    }
    return i0;
}

int main() {
    int q;
    cin >> q;

    for (int _ = 0; _ < q; _++) {
        ll a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);

        ll r = 0;
        if (a < b) {
            ll c = a * b;
            auto i = UpperBound<ll>(a, b, [&](auto i) {
                return i * i < c;
            });

            r = (i - a) * 2;
            r -= (i - 1) * i >= c;
            r -= r > 0;
        }
        r += (a - 1) * 2;

        cout << r << '\n';
    }

    return 0;
}