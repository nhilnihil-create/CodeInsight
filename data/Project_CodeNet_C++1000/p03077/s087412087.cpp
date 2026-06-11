#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    ll n, a[5];
    cin >> n;
    rep(i, 5) cin >> a[i];

    ll minv = *min_element(a, a + 5);
    ll ans = 5 + (n - 1) / minv;

    cout << ans << endl;
    return 0;
}
