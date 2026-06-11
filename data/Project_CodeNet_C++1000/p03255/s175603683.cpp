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

    ll r = 1LL << 60;
    for (int k = 1; k <= n; k++) {
        ll s = (ll)x * (n + k) + a[k] * 5;
        for (int i = k; i < n; i += k) {
            s += (a[min(i + k, n)] - a[i]) * ((i / k) * 2 + 3);
            if (s >= r) break;
        }
        r = min(r, s);
    }
    cout << r << endl;

    return 0;
}