#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    bool flag = false;
    rep(i, n) {
        cin >> a[i];
        if (a[i] > i || (i > 0 && a[i - 1] + 1 < a[i])) {
            flag = true;
        }
    }
    if (flag) {
        puts("-1");
        return 0;
    }
    ll ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] + 1 == a[i + 1])
            ans++;
        else
            ans += a[i + 1];
    }
    cout << ans << endl;
}