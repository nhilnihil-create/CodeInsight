#include <bits/stdc++.h>
using namespace std;

int gcd (int x, int y) {
    if (y == 0) {
        return x;
    }
    if (x % y == 0) {
        return y;
    }
    else {
        return gcd(y, x % y);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> l(n);
    vector<int> r(n);
    l[0] = 0;
    r[n - 1] = 0;
    for (int i = 0; i < n - 1; i++) {
        l[i + 1] = gcd(l[i], a[i]);
    }
    for (int i = n - 1; i > 0; i--) {
        r[i - 1] = gcd(r[i], a[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, gcd(l[i], r[i]));
    }
    cout << ans << endl;
    return 0;
}