#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

int dep[200010], dp[200010];
vector<int> adj[200010];
int d;

void dfs(int cur, int prev = -1) {
    for (int to : adj[cur]){
        if (to == prev) continue;
        
        dep[to] = dep[cur] + 1;
        dfs(to, cur);
        d = max(d, dp[cur] + 1 + dp[to]);
        dp[cur] = max(dp[cur], 1 + dp[to]);
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    puts(d % 3 != 1 ? "First" : "Second");
}