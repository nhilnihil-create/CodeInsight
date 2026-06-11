#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());

    int ans = 0;
    rep(i, n) {
        if (a[i] <= k) {
            k -= a[i];
            ans++;
        } else
            break;
    }

    if (k > 0 && ans == n)
        ans--;
    cout << ans << endl;

    return 0;
}
