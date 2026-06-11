#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int n, m, L = 0, R = INT_MAX, l, r;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        L = max(L, l);
        R = min(R, r);
    }
    int ans = R - L + 1;
    if (ans < 0) ans = 0;
    cout << ans << endl;
    return 0;
}