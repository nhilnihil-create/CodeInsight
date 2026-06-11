#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> l(n), r(n);
    l[0] = a[0];
    rep(i, n-1) l[i+1] = gcd(a[i+1], l[i]);
    r[n-1] = a[n-1];
    for (int i=n-1; i > 0; i--) r[i-1] = gcd(a[i-1], r[i]);
    int ans = 0;
    rep(i, n) {
        if (i==0) ans = max(ans, r[1]);
        else if (i==n-1) ans = max(ans, l[n-2]);
        else ans = max(ans, gcd(l[i-1], r[i+1]));
    }
    cout << ans << endl;
    return 0;
}