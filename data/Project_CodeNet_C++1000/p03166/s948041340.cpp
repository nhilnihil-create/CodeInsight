#include <bits/stdc++.h>
using namespace std;

int n, m;
int dp[100010];
vector<int> g[100010];

int calc(int u) {
    int &y = dp[u];
    if(y != -1) return y;
    y = 0;
    for(auto&v: g[u]) {
        y = max(y, 1+calc(v));
    }
    return y;
}

int main() {
    memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	while(m--) {
	    int x, y;
	    cin >> x >> y;
	    g[x].push_back(y);
	}
	int ans = 0;
	for(int i=1; i<=n; ++i) {
	    ans = max(ans, calc(i));
	}
	cout << ans << endl;
	return 0;
}
