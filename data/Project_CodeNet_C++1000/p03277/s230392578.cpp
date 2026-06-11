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

struct BIT {
    BIT(int n) : b(n + 1), n(n) {}
    void add(int i, int v) {
        for (int k = i + 1; k <= n; k += k & -k) b[k] += v;
    }
    int sum(int k) {
        int s = 0;
        for (; k > 0; k -= k & -k) s += b[k];
        return s;
    }
    void clear() {
        b.assign(n, 0);
    }
    vector<int> b;
    int n;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll t = ((ll)n * (n + 1) / 2 + 1) / 2;
    BIT bt(n * 2 + 1);

    auto j = UpperBound<int>(2, (int)1e9 + 1, [&](auto j) {
        ll r = 0;
        int s = n;
        bt.clear();
        bt.add(s, 1);
        for (int i = 0; i < n; i++) {
            s += a[i] >= j ? 1 : -1;
            r += bt.sum(s + 1);
            bt.add(s, 1);
        }
        return r >= t;
    });

    cout << j - 1 << endl;

    return 0;
}