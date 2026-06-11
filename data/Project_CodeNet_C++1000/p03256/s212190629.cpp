#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>

using namespace std;

void finish()
{
    cout << "Yes" << endl;
    exit(0);
}

int n, m;
string str;
vector< vector<int> > gr, color;

void dfs(int u, int col)
{
    char nxtch = (col == 3 || col == 0) ? 'A' : 'B';
    int nxtcol = (col + 1) % 4;

    for (int v : gr[u]) {
        if (str[v] != nxtch) continue;
        if (color[v][nxtcol] == 2) continue;
        if (color[v][nxtcol] == 1) finish();
        color[v][nxtcol] = 1;
        dfs(v, nxtcol);
    }

    color[u][col] = 2;
}

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    cin >> str;
	gr.resize(n);
	for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v; --u; --v;
        gr[u].push_back(v);
        gr[v].push_back(u);
	}

	color.assign(n, vector<int>(4, 0));

    for (int u = 0; u < n; ++u) {
        if (str[u] == 'A') {
            if (!color[u][0] && !color[u][1]) {
				color[u][0] = 1;
				dfs(u, 0);
            }
        } else {
            if (!color[u][2] && !color[u][3]) {
				color[u][2] = 1;
				dfs(u, 2);
            }
        }
    }

    cout << "No" << endl;
}
