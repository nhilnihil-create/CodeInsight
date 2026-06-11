///A drunk man will find his way home, but a drunk bird may get lost forever...i
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef pair <int, int> pii;
#define pb push_back
#define pf push_front
#define f first
#define s second
#define sz(x) (int)x.size()
#define smin(x , y) x = min(x , y)
#define mp make_pair
const int mx = 1000 * 100;
bool mark[mx];
vector < int > ad[mx], tpl;
int ans[mx], n;
void dfs(int v){
	mark[v] = 1;
	for(int u : ad[v])
		if(!mark[u])
			dfs(u);
	tpl.pb(v);
	return;
}
void dfs_all(){
	for(int i = 0; i < n; i++)
		if(!mark[i])
			dfs(i);
	return;
}
int32_t main(){		
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	int m, u, v;
	cin >> n >> m;
	for(int i = 0; i < n + m - 1; i++){
		cin >> u >> v;
		u--, v--;
		ad[u].pb(v);
	}
	dfs_all();
	reverse(tpl.begin(), tpl.end());
	for(int v : tpl)
		for(int u : ad[v])
			ans[u] = v + 1;
	for(int i = 0; i < n; i++)
		cout << ans[i] << endl;
	return 0;
}
