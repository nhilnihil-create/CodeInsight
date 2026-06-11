// author: Saman Mahdanian
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int N = 2e5 + 10;

int n, m;
vector <int> g[N];
int degA[N], degB[N];
string s;
bool mark[N];
queue <int> to_do;

int32_t main() {
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		int v, u;
		cin >> v >> u;
		v--; u--;
		g[v].push_back(u);
		g[u].push_back(v);
		if (s[v] == 'A')
			degA[u]++;
		else
			degB[u]++;
		if (s[u] == 'A')
			degA[v]++;
		else
			degB[v]++;
	}

	for (int v = 0; v < n; v++) {
		int all_same = true;
		for (int u: g[v])
			all_same &= s[u] == s[g[v][0]];
		if (all_same)
			to_do.push(v);
	}

	while (!to_do.empty()) {
		int v = to_do.front();
		to_do.pop();
		if (mark[v])
			continue;
		mark[v] = true;
		for (int u: g[v]) {
			if (s[v] == 'A')
				degA[u]--;
			else 
				degB[u]--;
			if (degA[u] == 0 || degB[u] == 0)
				if (!mark[u])
					to_do.push(u);
		}
	}

	for (int i = 0; i < n; i++)
		if (!mark[i]) {
			cout << "Yes" << endl;
			return 0;
		}
	cout << "No" << endl;
}
// SamMHD :: 21/11/2018 14:06:15 :: Another F****** graph...