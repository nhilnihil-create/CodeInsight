#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int k;
    cin >> k;
    vector<int> a(k);
    rep(i, k) cin >> a[i];
    reverse(a.begin(), a.end());

    ll l = 2, r = 2;
    for (int i = 0; i < k; i++) {
        l = (l - 1) / a[i] * a[i] + a[i];
        r = r / a[i] * a[i] + (a[i] - 1);
        if (l > r) {
            puts("-1");
            return 0;
        }
    }
    cout << l << " " << r << endl;
}