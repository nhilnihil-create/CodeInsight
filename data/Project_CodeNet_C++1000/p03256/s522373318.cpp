#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<queue>
#include<stack>
using namespace std;
#define vel vector<long long>
#define vvel vector<vel>
#define int long long
#define rep(i,n) for(long long i=0;i<n;i++)
#define sor(v) sort(v.begin(),v.end())
#define mmax(a,b) a=max(a,b)
#define mmin(a,b) a=min(a,b)
#define mkp make_pair
#define pin pair<int,int>
#define V vector
long long p = 998244353;
vel state;
int ru(int a, int r) {
	if (r == 0) { return 1; }
	int ans = ru(a, r / 2);
	ans *= ans; ans %= p;
	if (r % 2 == 1) { ans *= a; ans %= p; }
	return ans;
}
bool dfs(int i, vel &state,vvel &way) {
	if (state[i] == 2) { return false; }
	else if(state[i]==1){return true;}
	state[i] = 1;
	rep(j, way[i].size()) {
	    int to1 = way[i][j];
		if (dfs(to1, state, way)) { return true; }
	}
	state[i] = 2;
	return false;
}
signed main() {
	int n, m; cin >> n >> m;
	string c; cin >> c;
	vel st(2 * m), to(2 * m);
	rep(i, m) {
		cin >> st[i] >> to[i]; st[i]--; to[i]--;
		to[i + m] = st[i];
		st[i + m] = to[i];
	}
	vvel way(2 * n + 2 * m);
	rep(i, 2 * m) {
		int st1 = st[i];
		int to1 = to[i];
		if (c[st1] == c[to1]) {
			way[i].push_back(to1 + 2 * m);
			way[st1 + n + 2 * m].push_back(i);
		}
		else {
			way[i].push_back(to1 + n + 2 * m);
			way[st1 + 2 * m].push_back(i);
		}
	}
	int sz = 2 * n + 2 * m;
	state=vel(sz,0);
	rep(i, sz) {
		if (dfs(i, state, way)) {
			cout << "Yes" << endl; return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}