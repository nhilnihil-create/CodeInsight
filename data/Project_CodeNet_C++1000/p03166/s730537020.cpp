#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
#include <stack>
#include <vector>
#include <random>
#include <string.h>
#include <stdio.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef pair<int, int> ii;
typedef pair<long double, int> id;
typedef pair<long long, long long> llp;
const int N = 1e5+1;
int n, m;
int dp[N];
bool visit[N];
vector<int> a[N];
void dfs(int u) {
    visit[u] = 1;
    for(int v:a[u]) {
        if (!visit[v]) dfs(v);
        dp[u] = max(dp[u], dp[v]+1);
    }
}
int main() {
    //freopen("ee.inp", "r", stdin);
    //freopen("ee.OUT", "w", stdout);
    fastIO;
    cin>>n>>m;
    int u, v, ans = 0;
    for(int i=1;i<=m&&cin>>u>>v;i++) a[u].push_back(v);
    for(int i=1;i<=n;i++) if (!visit[i]) dfs(i);
    for(int i=1;i<=n;i++) ans = max(ans, dp[i]);
    cout << ans;
}
