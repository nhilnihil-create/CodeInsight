#include <bits/stdc++.h>
using namespace std;

signed main () {
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    vector < int64_t > a(x), b(y), c(z);
    for (int i = 0; i < x; ++i)
        cin >> a[i];
    for (int i = 0; i < y; ++i)
        cin >> b[i];
    for (int i = 0; i < z; ++i)
        cin >> c[i];
    vector < int64_t > ab, abc;
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j)
            ab.push_back(a[i] + b[j]);
    }
    sort(ab.rbegin(), ab.rend());
    for (int i = 0; i < z; ++i) {
        for (int j = 0; j < min(k, int(ab.size())); ++j) 
            abc.push_back(c[i] + ab[j]);
    }
    sort(abc.rbegin(), abc.rend());
    for (int i = 0; i < k; ++i)
        cout << abc[i] << '\n';
}
