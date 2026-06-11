#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

const int N = 1e5;
vector<int> adj[N];
vector<int> dp(N, -1);

int rec(int v) {
    if (dp[v] != -1) return dp[v];
    int ans = 0;
    for (int u : adj[v])
        ans = max(ans, rec(u) + 1);
    dp[v] = ans;
    return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, rec(i));
    cout << ans << endl;

	return 0;
}