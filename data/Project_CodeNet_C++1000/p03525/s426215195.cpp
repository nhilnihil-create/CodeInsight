#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout << (x) << endl
#define Int int64_t
#define fi first
#define se second

Int INF = 1e9;
Int mod = 1e9+7;

int main() {
    Int n;
    cin >> n;
    vector<Int> d(n);
    for (Int i = 0; i < n; i++) {
        cin >> d[i];
        d[i] = min(d[i], 24 - d[i]);
    }
    d.push_back(0);
    sort(d.begin(), d.end());
    for (Int i = 0; i <= n; i+=2) {
       d[i] = (24 - d[i]) % 24;
    }
    sort(d.begin(), d.end());
    Int res = d.back() - d.front();
    for (Int i = 0; i < n; i++) {
        res = min(res, d[i + 1] - d[i]);
    }
    dump(res);
    return 0;
}