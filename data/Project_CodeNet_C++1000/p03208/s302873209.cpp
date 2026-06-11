#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int h[n];
    rep(i, n) cin >> h[i];
    sort(h, h + n);

    int ans = 1e9;
    rep(i, n - k + 1) ans = min(ans, h[i + k - 1] - h[i]);

    cout << ans << endl;
    return 0;
}
