#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

const int N = 200005;
const int MOD = 1000000007;

int dp[N], c[N];
vi v[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        v[c[i]].pb(i);
        if (v[c[i]].size() == 1) {
            dp[i] = dp[i - 1];
            continue;
        }
        int u = v[c[i]][v[c[i]].size() - 2];
        if (u == i - 1) {
            dp[i] = dp[u];
        } else {
            dp[i] = (dp[i - 1] + dp[u]) % MOD;
        }
    }
    cout << dp[n];
    return 0;
}