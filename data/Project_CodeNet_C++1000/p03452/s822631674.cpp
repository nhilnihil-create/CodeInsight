//IOI 2021

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100 * 1000 + 17;

int n, m, dp[MAXN], col[MAXN], IN[MAXN];
vector<pii> adj[MAXN], adj_in[MAXN];
bool mark[MAXN];
vector<int> topol;
stack<int> topol_tmp;

void check_cyc(int v) {
	col[v] = 1;
	for (auto u : adj[v])
		if (col[u.ff] == 1) {
			cout << "No" << endl;
			exit(0);
		}
		else if (!col[u.ff])
			check_cyc(u.ff);
		else
			;
	col[v] = 2;
}

void dfs_topol(int v) {
	mark[v] = true;
	for (auto i : adj[v])
		if (!mark[i.ff])
			dfs_topol(i.ff);
	topol_tmp.push(v);
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int l, r, d;
		cin >> l >> r >> d;
		IN[r]++;
		adj[l].pb({r, d});
		adj_in[r].pb({l, d});
	}
	for (int i = 1; i <= n; i++)
		if (!col[i])
			check_cyc(i);
	for (int i = 1; i <= n; i++)
		if (!IN[i])
			dfs_topol(i);
	while (topol_tmp.size())
		topol.pb(topol_tmp.top()), topol_tmp.pop();
	for (auto i : topol)
		if (IN[i]) {
			int x = dp[adj_in[i][0].ff] + adj_in[i][0].ss;
			for (auto j : adj_in[i])
				if (dp[j.ff] + j.ss != x) {
					cout << "No" << endl;
					return 0;
				}
			dp[i] = x;
		}
	cout << "Yes" << endl;
	return 0;
}
