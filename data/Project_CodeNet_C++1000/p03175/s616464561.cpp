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
const int mod = 1e9 + 7;

vector<int> G[maxn];
int dp[maxn][2] = {};

void dfs(int now,int fa) {
	dp[now][0] = dp[now][1] = 1;
	for (int k:G[now]) {
		if (k ^ fa) {
			dfs(k, now);
			dp[now][1] = (dp[k][0] * dp[now][1]) % mod;
			dp[now][0] = ((dp[k][1] + dp[k][0]) * dp[now][0]) % mod; 
		}
	}
}

main() {
	int n;
	cin >> n;
	
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	
	dfs(1, 0);
	cout << (dp[1][1] + dp[1][0]) % mod << "\n";

}
