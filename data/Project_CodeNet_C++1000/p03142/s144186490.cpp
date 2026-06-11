#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

vector<vector<int>> v;
int pnum[100100];
int ans[100100];

void dfs(int i) {
	for(int j: v[i]) if (--pnum[j] == 0) ans[j] = i + 1;
	for(int j: v[i]) if (pnum[j] == 0) dfs(j);
}

int main() {
	int n, m;
	cin >> n >> m;
	v.resize(n);
        rep(i, n - 1 + m) {
                int s, t;
                cin >> s >> t;
                s--; t--;
                v[s].push_back(t);
		pnum[t]++;
        }
	int root;
	rep(i, n) if (pnum[i] == 0) root = i;
	dfs(root);
	rep(i, n) cout << ans[i] << endl;
}