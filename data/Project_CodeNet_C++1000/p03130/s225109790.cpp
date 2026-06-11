#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define ALL(A) A.begin(), A.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

vector<int> G[4];
bool used[4];

bool dfs(int u, int depth){
	if (depth == 3){
		return true;
	} // end if

	used[u] |= true;
	bool res = false;
	rep (i, (int)G[u].size()){
		int v = G[u][i];
		if (!used[v]){
			res |= dfs(v, depth + 1);
		} // end if
	} // edn rep

	return res;
}

int main()
{
	rep (i, 4) G[i].clear();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	rep (i, 3){
		int a, b; cin >> a >> b;
		--a, --b;
		G[a].push_back(b);
		G[b].push_back(a);
	} // end rep

	memset(used, false, sizeof(used));
	bool res = dfs(0, 0);

	cout << (res ? "YES" : "NO") << endl;

	return 0;
}