#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;

template <class F>
int upper_bound(int i0, int i1, F f) {
    while (i0 < i1) {
        int i = (i0 + i1) / 2;
        if (f(i)) i0 = i + 1; else i1 = i;
    }
    return i0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    vector<ll> a(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[n - i];
    }
    for (int i = 0; i < n; i++) {
        a[i + 1] += a[i];
    }

    vector<ll> g(n + 1);
    auto f = [&](int k) {
        if (g[k]) return g[k];

        ll s = (ll)x * (n + k) + a[k] * 5;
        for (int i = k; i < n; i += k) {
            s += (a[min(i + k, n)] - a[i]) * ((i / k) * 2 + 3);
        }
        return g[k] = s;
    };

    int k = upper_bound(1, n, [&](int k) {
        return f(k + 1) - f(k) < 0;
    });
    cout << f(k) << endl;

    return 0;
}