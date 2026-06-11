#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using ll = long long;

int gcd(int x, int y) {
    if (x%y == 0) {
        return y;
    }
    return gcd(y, x%y);
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    rep(i,n) {
        cin >> a[i];
    }

    vector<int> l(n), r(n);
    l[0] = a[0];
    for (int i = 0; i < n-1; i++) {
        l[i+1] = gcd(l[i], a[i+1]);
    }
    r[n-1] = a[n-1];
    for (int i = n-1; i > 0; i--) {
        r[i-1] = gcd(r[i], a[i-1]);
    }


    int ans = 1;
    rep(i, n) {
        if (i == 0) {
            ans = max(r[1], ans);
            continue;
        }
        if (i == n-1) {
            ans = max(l[n-2], ans);
            continue;
        }
        ans = max(gcd(l[i-1], r[i+1]), ans);
    }

    cout << ans << endl;

    return 0;
}