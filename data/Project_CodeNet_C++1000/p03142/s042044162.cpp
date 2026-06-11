#include <bits/stdc++.h>
using namespace std;

#define name ""
#define ini freopen(name".inp","r",stdin); freopen(name".out","w",stdout)
#define foe(it,c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define long long long 
#define db double 
#define pii pair <int, int>
#define pll pair <long, long>
#define all(c) c.begin(), c.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const int INF = 1e9+7;
const int MOD = 1e9+7;
const int dx[4] = {0,0,-1,1};
const int dy[4] = {-1,1,0,0};

const int N = 1e5+1;
int n, m, deg[N], pa[N];
vector <int> a[N];

int main()
{
	fastio;
	cin >> n >> m;
	for (int i = 1; i <= n + m; i++){
		int u, v; cin >> u >> v;
		a[u].push_back(v);
		deg[v]++;		
	}
	
	queue <int> Q;
	
	for (int i = 1; i <= n; i++){
		if (deg[i] == 0) Q.push(i);
	}

	while (Q.size()){
		int u = Q.front();
		Q.pop();
		for (int v : a[u]){
			deg[v]--;
			if (deg[v] == 0){
				pa[v] = u;
				Q.push(v);
			}
		}
	}

	for (int i = 1; i <= n; i++) cout << pa[i] << '\n';

	return 0;
}