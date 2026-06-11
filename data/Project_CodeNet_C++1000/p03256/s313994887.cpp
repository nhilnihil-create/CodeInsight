#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#define N 200005
using namespace std;

int n, m, c[N][2], vt[N];
string s;
vector<int> gr[N];
queue<int> qu;

int main() {
	int i, u, v;
	cin >> n >> m >> s;
	s = '.' + s;
	while(m--) {
		scanf("%d%d", &u, &v);
		gr[u].push_back(v);
		gr[v].push_back(u);
		c[u][s[v]-'A']++;
		c[v][s[u]-'A']++;
	}
	for(i=1; i<=n; i++) if(!c[i][0] || !c[i][1]) {
		vt[i] = 1;
		qu.push(i);
	}
	while(!qu.empty()) {
		u = qu.front(); qu.pop();
		for(int v:gr[u]) {
			c[v][s[u]-'A']--;
			if(!vt[v] && !c[v][s[u]-'A']) {
				vt[v] = 1;
				qu.push(v);
			}
		}
	}
	for(i=1; i<=n && vt[i]; i++);
	puts(i>n ? "No" : "Yes");
	return 0;
}