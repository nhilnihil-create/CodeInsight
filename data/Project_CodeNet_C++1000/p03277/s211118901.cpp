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
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b(a);
    sort(b.begin(), b.end());

    ll th = ((ll)n * (n + 1) / 2 + 1) / 2;
    vector<int> c(n * 2 + 1);

    auto h = UpperBound<int>(1, n, [&](auto h) {
        int j = b[h];
        ll r = 0;
        int s = n, t = 0;
        fill(c.begin(), c.end(), 0);
        c[s]++;
        t++;
        for (int i = 0; i < n; i++) {
            if (a[i] >= j) {
                t += c[++s];
            } else {
                t -= c[s--];
            }
            r += t;
            c[s]++;
            t++;
        }
        return r >= th;
    });

    cout << b[h - 1] << endl;

    return 0;
}