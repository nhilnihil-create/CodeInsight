#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
// Welcome to my source code!

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= i + 1;
    }
    sort(a, a+n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(a[i] - a[n / 2]);
    }
    cout << ans << endl;
}