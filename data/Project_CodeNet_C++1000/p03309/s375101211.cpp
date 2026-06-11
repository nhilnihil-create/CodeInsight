#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        x -= i + 1;
        a[i] = x;
    }
    sort(a.begin(), a.end());
    ll b = a[(n % 2 == 1 ? (n - 1) / 2 : n / 2 - 1)];
    ll ans = 0;
    for (int i : a) {
        ans += abs(i - b);
    }
    cout << ans << endl;
}
