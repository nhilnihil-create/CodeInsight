//### In The Name Of GOD ###

//%% Remember; (((He))) is The (((Accepter))) %%

// GOD IS GREATER ...

#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef long double ld ;

//#define int ll
#define pb push_back
#define bp pop_back
#define pf push_front
#define fp pop_front
#define X first
#define Y second
#define IO ios_base::sync_with_stdio(false);
#define sz(a) (int)(a.size())
#define sg(a, b) (a + b - 1) /b

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 1 * 1000 * 1000 * 1000 + 200;
const int MAXN = 100 * 1000 + 10;
const int MLOG = 30;
const int NMAX = 20;

int n, mark[MAXN];
vector <pair<int, int>> adj[MAXN];

void dfs(int a) {
	//cout << a << ' ' << mark[a] - INF << endl;
	for(auto pr : adj[a]) {
		if(!mark[pr.X]) {
			mark[pr.X] = mark[a] + pr.Y;
			dfs(pr.X);
		}
	}
}

bool check() {
	for(int i = 0; i < n; i++) {
		for(auto pr : adj[i]) {
			if(mark[i] == mark[pr.X] - pr.Y) continue;
			else  return false;
		}
	}
	return true;
}

signed main() {
	int m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int l, r, d;
		cin >> l >> r >> d;
		l--;
		r--;
		adj[l].pb({r, d});
		adj[r].pb({l, -d});
	}
	for(int i = 0; i < n; i++) {
		if(!mark[i]) {	
			mark[i] = INF;
			dfs(i);
		}
	}
	if(check()) cout << "Yes";
	else cout << "No";
}

