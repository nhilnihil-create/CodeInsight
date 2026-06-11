#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    int n, m, l, r;
    cin >> n >> m;
    int lmax = 1, rmin = n;
    rep(i, m) {
        cin >> l;
        cin >> r;
        lmax = max(lmax, l);
        rmin = min(rmin, r);
    }
    cout << max(rmin - lmax + 1, 0) << endl;
    return 0;
}