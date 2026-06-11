#include <bits/stdc++.h>
using namespace std;
const int MAXn = 2e5 + 10;
typedef pair<int, bool> pib;

vector<int> g[MAXn], vecb, veca;
bool flag[MAXn][2], aorb[MAXn];
int n, m, dega[MAXn], degb[MAXn], sz[MAXn], cnt;
set<int> st;
void dela(int a) {
	if (st.find(a) != st.end())
		return ;
	st.insert(a);
	for (int i = 0; i < g[a].size(); i++) {
		--dega[g[a][i]];
		if (0 == dega[g[a][i]]) {
			if (aorb[g[a][i]] == 0)
			veca.push_back(g[a][i]);
			else
			vecb.push_back(g[a][i]);
		}
	}
}

void delb(int a) {
	if (st.find(a) != st.end())
		return ;
	st.insert(a);
	for (int i = 0; i < g[a].size(); i++) {
		--degb[g[a][i]];
		if (0 == degb[g[a][i]]) {
			if (aorb[g[a][i]] == 0)
			veca.push_back(g[a][i]);
			else
			vecb.push_back(g[a][i]);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		char ch;
		cin >> ch;
		if (ch == 'B')
			aorb[i] = 1;
	}
	
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;u--; v--;
		
		if (aorb[u])
			degb[v]++;
		else
			dega[v]++;
			
		if (v != u && aorb[v])
			degb[u]++;
		else if (v != u)
			dega[u]++;
				
		g[u].push_back(v);
		if (v != u)
			g[v].push_back(u);
	}
	for (int i = 0; i < n; i++) {
		if (dega[i] == 0 || degb[i] == 0) {
			if (aorb[i] == 0)
			veca.push_back(i);
			else
			vecb.push_back(i);
		}
	}
	int i = 0, j = 0;
	while((i != veca.size() || j != vecb.size())) {
		for ( ; i < veca.size(); i++)
			dela(veca[i]);
		for ( ; j < vecb.size(); j++)
			delb(vecb[j]);
	}
	if (st.size() != n)
		return cout << "Yes",0;
	cout << "No";
}