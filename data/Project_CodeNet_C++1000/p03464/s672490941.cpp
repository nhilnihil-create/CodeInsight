#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int k; 
    cin >> k;
    ll a[k];
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }

    ll h = 2, l = 2;
    for (int i = k - 1; i >= 0; i--) {
        ll qh = h / a[i];
        ll ql = (l + a[i] - 1) / a[i];
        if (qh < ql) {
            cout << -1 << endl;
            return 0;
        }
        h = a[i] * (qh + 1) - 1;
        l = a[i] * ql;
    }
    cout << l << " " << h << endl;
    return 0;
}