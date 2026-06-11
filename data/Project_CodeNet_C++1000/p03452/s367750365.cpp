#include <bits/stdc++.h>
using namespace std;

const int MAXM = 2e5 + 10, MAXN = 1e5 + 10, INF = 2e9 + 10;

int n, m;
int l, r, d;
long long mark[MAXN];
vector <pair <int, int> > adj[MAXN];

void dfs(int a) {
	for(auto pr : adj[a]) {
		if(!mark[pr.first]) {
			mark[pr.first] = mark[a] + pr.second;
			dfs(pr.first);
		}
	}
}
 
bool check() {
	for(int i = 0; i < n; i++) {
		for(auto pr : adj[i]) {
			if(mark[i] == mark[pr.first] - pr.second) 
                continue;
			else  
                return false;
		}
	}
	return true;
}
 
signed main() {
	cin >> n >> m;
	
    for(int i = 0; i < m; i++) {
		cin >> l >> r >> d;
		l--;
		r--;
		adj[l].push_back({r, d});
		adj[r].push_back({l, -d});
	}
	
    for(int i = 0; i < n; i++) {
		if(!mark[i]) {	
			mark[i] = INF;
			dfs(i);
		}
	}

	if(check()) 
        cout << "Yes" << '\n';
	else 
        cout << "No" << '\n';
    return 0;
}
