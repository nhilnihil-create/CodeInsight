#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    ll a[n], b[n];
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    ll k = 0, two = 0;
    rep(i, n) {
        ll d = b[i] - a[i];
        k += d;
        if (d > 0) two += (d + 1) / 2;
    }

    if (two <= k)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
