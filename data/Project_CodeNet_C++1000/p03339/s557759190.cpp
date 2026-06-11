#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int>w(n + 1), e(n + 1);
    int sw = 0, se = 0;
    vector<char> s(n);
    for (int i = 0; i < n; i++) {
        char x;
        cin >> x;
        s[i] = x;
        if(s[i] == 'W') {
            sw++;
        }
        else {
            se++;
        }
        w[i + 1] = sw;
        e[i + 1] = se;
    }
    int ans = 3 * 1e5 + 1;
    for (int i = 0; i <= n; i++) {
        ans = min(ans, w[i - 1] + e[n] - e[i]);
    }
    cout << ans;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
