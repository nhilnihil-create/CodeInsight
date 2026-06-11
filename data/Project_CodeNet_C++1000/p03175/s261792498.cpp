#include <bits/stdc++.h>
using namespace std;
long dp[100001][2];
vector<int> tree[100001];
void solve(int n, int p) {
    if(dp[n][0] > -1) return;
    if(tree[n].size() == 1 && tree[n][0] == p) {
        dp[n][0] = dp[n][1] = 1;
        return;
    }
    long r = 1, b = 1;
    for(auto i : tree[n]) {
        if(i == p) continue;
        solve(i, n);
        b = (b * dp[i][1]) % 1000000007;
        r = (r * (dp[i][0] + dp[i][1])) % 1000000007;
    }
    dp[n][0] = b;
    dp[n][1] = r;
    return;
}
int main() {
    int n, i, x, y;
    cin >> n;
    for(i = 1; i <= n; ++i) dp[i][0] = dp[i][1] = -1; 
    for(i = 1; i < n; ++i) {
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    solve(1, 0);
    cout << (dp[1][0] + dp[1][1]) % 1000000007;
    return 0;
}