#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ans += x - 1;

    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
