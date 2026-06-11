#include <bits/stdc++.h>

#define pb push_back

using namespace std;

const int MXN = 1e5+5;

int N, M, x, y, ans = 0;
int seen[MXN];
vector<int> edges[MXN];

int dfs(int c)
{
	if (seen[c] == -1) {
		int biggest = 0;
		for (int neighbour : edges[c]) {
			dfs(neighbour); biggest = max(biggest,seen[neighbour]+1);
		} 
		seen[c] = biggest;
	}
	return seen[c];
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i=0;i<M;++i) {
		cin >> x >> y;
		edges[x].pb(y);
	}
	for (int i=0;i<MXN;++i) seen[i] = -1;
	for (int i=1;i<=N;++i) {
		dfs(i);
		ans = max(ans,seen[i]);
	}
	cout << ans << '\n';
	return 0;
}