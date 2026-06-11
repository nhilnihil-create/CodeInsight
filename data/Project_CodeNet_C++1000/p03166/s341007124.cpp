
// Problem: G - Longest Path
// Contest: AtCoder - Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_g
// Parsed on: 2020-09-07 09:26:37
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);

using namespace std;

int solve(vector<vector<int>> const &graph, int startNode, vector<int> &dp) {
    if (dp[startNode] != -1) return dp[startNode];

    if (graph[startNode].empty()) {
        dp[startNode] = 0;
        return 0;
    } else {
        int ans = -1;
        for (int a = 0; a < graph[startNode].size(); a++) {
            int node = graph[startNode][a];
            ans = max(ans, solve(graph, node, dp));
        }
        dp[startNode] = ans + 1;
        return dp[startNode];
    }
}

int main() {
    fastio int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>()), revG(n, vector<int>());
    vector<int> endpoints;
    vector<bool> edp(n, true);
    for (int t = 0; t < m; t++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        revG[b].push_back(a);
        edp[a] = false;
    }

    for (int a = 0; a < n; a++)
        if (edp[a]) endpoints.push_back(a);

    vector<int> dp(n, -1);

    int ans = -1;
    for (auto &e : endpoints) ans = max(ans, solve(revG, e, dp));
	cout << ans;
    //for (auto &e : dp) cerr << e << " ";

    return 0;
}
