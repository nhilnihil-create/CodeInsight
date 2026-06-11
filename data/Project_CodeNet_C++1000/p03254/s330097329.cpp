#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (x - a[i] < 0) break;

        if (i == n - 1) {
            if (x - a[i] == 0) ans++;
        } else {
            x -= a[i];
            ans++;
        }
    }

    cout << ans << endl;
}