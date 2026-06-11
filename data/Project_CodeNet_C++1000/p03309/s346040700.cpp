#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    rep(i, n) {
        cin >> a[i];
        a[i] -= i + 1;
    }
    sort(a, a + n);

    ll ans = 0;
    rep(i, n) ans += abs(a[i] - a[n / 2]);
    cout << ans << endl;
    return 0;
}
