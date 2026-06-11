#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;

signed main() {
    int m, k;
    cin >> m >> k;
    int n = 1 << m;
    if (k == 0) {
        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            cout << i << " " << i;
        }
        cout << endl;
        return 0;
    }
    if (n <= k) {
        cout << -1 << endl;
        return 0;
    }
    int ans[n * 2];
    ans[0] = k;
    ans[n] = k;
    int cur = 0;
    for (int i = 1; i < n; i++) {
        if (cur == k) cur++;
        ans[n - i] = cur;
        ans[n + i] = cur;
        cur++;
    }
    int sum[n * 2 + 1] = {};
    for (int i = 0; i < n * 2; i++) {
        sum[i + 1] = sum[i] ^ ans[i];
    }
    int pre[n];
    fill(pre, pre + n, -1);
    for (int i = 0; i < n * 2; i++) {
        if (pre[ans[i]] == -1) {
            pre[ans[i]] = i;
        } else if ((sum[pre[ans[i]]] ^ sum[i + 1]) != k) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = 0; i < n * 2; i++) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}