#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <cstring>
//#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define de(x,y) cout<<#x<<" :"<<x<<y;
#define int long long
#define SZ(xx) ((int)xx.size())
#define lowbit(xx) (xx&(-xx))
#define pb push_back
typedef pair<int,int> pii;

const int maxn = 4e5+5;

vector<int> G[maxn];
int ans = 0;
int ing[maxn] = {};
bool vis[maxn] =  {};
int dp[maxn] = {};
void dfs(int now) {
	vis[now] = 1;
	for (int k:G[now]) {
		dp[k] = max(dp[k], dp[now] + 1);
		ing[k]--;
		if (!ing[k])
			dfs(k);
	}
}

main() {
	IOS
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		G[u].pb(v);
		ing[v]++;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i] && !ing[i]) {
			dfs(i);
		}
	}
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		mx = max(mx, dp[i]);
	}
	cout << mx << "\n";
}
