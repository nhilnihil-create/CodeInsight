#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <deque>
#include <queue>
#include <climits>
#include <set>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ve vector
#define umap unordered_map
#define iter iterator
int n, m, a[10000], b[10000], col[10000], c, res;
vector<int>x[100];

void dfs(int pos) {
	if (col[pos] >= 1) return;
	col[pos] = c;
	for (int j = 0; j < x[pos].size(); j++)dfs(x[pos][j]);
}

void solve() {
	cin >> n >> m;
	for (int i=0; i<m; i++) cin >> a[i] >> b[i];
	for (int i=0; i<m; i++) {
		for (int j=0; j<=n; j++) { x[j].clear(); col[j] = 0; }
		for (int j=0; j<m; j++) {
            if (i != j) {
                x[a[j]].push_back(b[j]);
                x[b[j]].push_back(a[j]);
            }
        }
		c = 0;
		for (int j=1; j<=n; j++) {
            if (col[j] >= 1) continue;
            c++;
            dfs(j);
        }
		if (c >= 2) res++;
	}
	cout << res << endl;
}

int main() {
    solve();
    return 0;
}