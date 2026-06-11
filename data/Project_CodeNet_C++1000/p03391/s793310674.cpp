#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n; cin >> n;
    vector<ll> a(n), b(n);
    ll sum = 0;
    for(int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        sum += a[i];
    }

    ll ans = 0;
    for(int i = 0; i < n; ++i) {
        if(a[i] <= b[i]) continue;
        ans = max(ans, sum - b[i]);
    }
    cout << ans << endl;
}