#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
int n;
vector<vector<int>> a;
ll dp[1 << 21];
bool done[1 << 21];
ll dfs(int rest, int line) {
    if (done[rest]) {
        // cout << "memo" << endl;
        return dp[rest];
    }
    if (line == n - 1) {
        for (int j = 0; j < n; j++) 
            if (a[line][j] == 1 && rest & 1<<j) return 1;
            return 0;
    }
    done[rest] = true;
    ll res = 0;
    for (int i = 0; i < n; i++) {
        if (rest & 1<<i && a[line][i] == 1) {
            rest ^= 1<<i;
            res += dfs(rest, line+1);
            res %= MOD;
            rest ^= 1<<i;
        }
    }
    // cout << res << endl;
    return dp[rest] = res;
}

int main() {
    cin >> n;
    a.assign(n, vector<int>(n));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
    int rest = (1<<n) - 1;
    ll ans = dfs(rest, 0);
    cout << ans << endl;
    // for (auto d: done) cout << d.second << endl;
    return 0;
}