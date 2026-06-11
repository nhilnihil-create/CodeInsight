#include<bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 13;
int n, lvl[maxN], mx, nd;
vector<int> adj[maxN];
void dfs (int x, int p) {
    if (lvl[x] > mx) {
	mx = lvl[x];
	nd = x;
    }
    for (auto a : adj[x]) {
	if (a != p) {
	    lvl[a] = lvl[x] + 1;
	    dfs(a, x);
	}
    }
}

int main () {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
	int a, b;
	cin >> a >> b;
	adj[a].push_back(b);
	adj[b].push_back(a);
    }
    lvl[1] = 1;
    dfs(1, 1);
    mx = 0;
    lvl[nd] = 1;
    dfs(nd, nd);
    if (mx % 3 == 2)
	cout << "Second" << endl;
    else
	cout << "First" << endl;
    
}
