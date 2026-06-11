#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int, int, int> T;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int n, m;
vvi e, rev;
V<bool> root;
vi tpr;

void dfs(int v) {
	rep(i, e[v].size()) {
		if (root[e[v][i]])continue;
		root[e[v][i]] = true;
		dfs(e[v][i]);
	}
	tpr.push_back(v);
	return;
}

int main() {

	cin >> n >> m;
	e.resize(n);
	rev.resize(n);
	root.assign(n, true);

	rep(i, n - 1 + m) {
		int a, b;
		cin >> a >> b;
		a--;b--;
		e[a].push_back(b);
		rev[b].push_back(a);
		root[b] = false;
	}

	rep(i, n)if (root[i]) { dfs(i);break; }
	
	vi ans(n, 0);
	reverse(all(tpr));
	rep(i, tpr.size())rep(j, e[tpr[i]].size()) {
		ans[e[tpr[i]][j]] = tpr[i] + 1;
	}
	
	for (auto x : ans)cout << x << endl;

}