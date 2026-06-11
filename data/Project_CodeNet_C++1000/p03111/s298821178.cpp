#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

int n, a, b, c;
int l[10];
int sum[4], cnt[4];
int ans;
void dfs(int i) {
    if (i == n) {
        if (!cnt[1] || !cnt[2] || !cnt[3]) return;
        ans = min(ans, (cnt[1] + cnt[2] + cnt[3] - 3) * 10 + abs(a - sum[1]) + abs(b - sum[2]) + abs(c - sum[3]));
        return;
    }
    for (int j = 0; j < 4; ++j) {
        sum[j] += l[i];
        ++cnt[j];
        dfs(i + 1);
        --cnt[j];
        sum[j] -= l[i];
    }
}
int main() {
    ans = 1e9;
    cin >> n >> a >> b >> c;
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }
    dfs(0);
    cout << ans << endl;
    return 0;
}
