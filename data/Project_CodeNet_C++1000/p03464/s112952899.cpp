#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int k; cin >> k;
    vector<ll> a(k); for (int i = 0; i < k; i++) cin >> a[i];
    ll min = 2, max = 2;
    for (int i = k-1; i >= 0; i--) {
        ll n = (min + a[i] - 1) / a[i] * a[i];
        ll nn = max / a[i] * a[i] + a[i] - 1;
        if (n > max || nn < min) {
            cout << -1 << endl;
            return 0;
        }
        min = n;
        max = nn;
    }
    cout << min << " " << max << endl;
    return 0;
}