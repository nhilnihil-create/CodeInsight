#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

#define int int64_t
#define ld long double

const int MOD = 1e9+7;
const int N = 1e5+5;

vector<int> adj[N];
int ans[N][2];
int n;

void dfs(int x, int p) {
	if(adj[x].size()==1 && x>1) {
		ans[x][0]=1;
		ans[x][1]=1;
		return;
	}
	int bans=1, wans=1;
	for(int i: adj[x]) {
		if(i==p)
			continue;
		dfs(i, x);
		int bcnt = ans[i][0];
		int wcnt = ans[i][1];
		bans = (bans*wcnt)%MOD;
		wans = (wans*(wcnt+bcnt))%MOD;
	}
	ans[x][0]=bans;
	ans[x][1]=wans;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	int u,v;
	for(int i=1;i<n;i++) {
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(1, -1);

	cout<<(ans[1][0]+ans[1][1])%MOD;

	return 0;
}