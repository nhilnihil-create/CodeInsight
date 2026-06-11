#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        a[i] *= n;
    }
    constexpr long long LLINF = 1e18 + 1;
    ll now = LLINF, m;
    for (int i = 0; i < n; i++) {
        if (now > abs(sum - a[i])) {
            now = abs(sum - a[i]);
            m = i;
        }
    }
    cout << m << endl;
    return 0;
}