#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;

int d1[maxn], d2[maxn];
int n, m;
string s;
bool mark[maxn];
queue <int> que;
vector<int> g[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m >> s;
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		if(u != v) {
			g[u].push_back(v);
			g[v].push_back(u);
			if(s[v] == 'A')
				d1[u]++;
			else
				d2[u]++;
			if(s[u] == 'A')
				d1[v]++;
			else
				d2[v]++;
		}
		else {
			g[u].push_back(u);
			if(s[v] == 'A')
				d1[u]++;
			else
				d2[u]++;
		}
	}
	
	for(int i = 0; i < n; i++) {
		if(d1[i] == 0 || d2[i] == 0) {
			que.push(i);
		}
	}
	
	while(que.size()) {
		int u = que.front();
		mark[u] = true;
//		cout << "del : " << u + 1 << endl;
		
		for(int i = 0; i < g[u].size(); i++) {
			int v = g[u][i];
			if(!mark[v]) {
				if(s[u] == 'B')
					d2[v]--;
				else
					d1[v]--;
				if((d1[v] == 0 && s[u] == 'A') || (d2[v] == 0 && s[u] == 'B')) {
					que.push(v);
				}
			}
		}
		que.pop();
	}
	
	int x = 0;
	for(int i = 0; i < n; i++) {
		if(!mark[i])
			x++;//, cout << i + 1 << " ";
	}
	
	if(x != 0)
		cout << "Yes";
	else
		cout << "No";
}