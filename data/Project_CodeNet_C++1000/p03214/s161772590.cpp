#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    double ave = 0;
    rep(i, n) ave += a[i];
    ave /= n;

    double sa = INF;
    int ans = 0;

    for (int i = n - 1; i >= 0; --i) {
        if (sa >= abs(ave - a[i])) {
            ans = i;
            sa = abs(ave - a[i]);
        }
    }

    cout << ans << endl;

    return 0;
}
