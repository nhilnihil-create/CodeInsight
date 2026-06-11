#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 10;
int n, m;
string s;
vector <int> G[MAX_N];
int cnt_A[MAX_N];
int cnt_B[MAX_N];
bool Mark[MAX_N];
vector <int> Q;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		int v, u;
		cin >> v >> u;
		v--; u--;
		G[v].push_back(u);
		G[u].push_back(v);
		if (s[u] == 'A')
			cnt_A[v]++;
		else
			cnt_B[v]++;
		if (s[v] == 'A')
			cnt_A[u]++;
		else
			cnt_B[u]++;	
	}
	
	for (int i = 0; i < n; i++)
		if (cnt_A[i] == 0 || cnt_B[i] == 0) {
			Q.push_back(i);
			Mark[i] = true;
		}
	
	while (Q.size()) {
		int v = Q.back();
		Q.pop_back();
		
		for (int i = 0; i < G[v].size(); i++)
			if (!Mark[G[v][i]]) {
				if (s[v] == 'A')
					cnt_A[G[v][i]]--;
				else
					cnt_B[G[v][i]]--;
				if (cnt_A[G[v][i]] == 0 || cnt_B[G[v][i]] == 0) {
					Q.push_back(G[v][i]);
					Mark[G[v][i]] = true;
				}
			}
	}
	
	bool ok = false;
	for (int i = 0; i < n; i++)
		if (!Mark[i])
			ok = true;
	
	cout << (ok? "Yes": "No");
	return 0;
}