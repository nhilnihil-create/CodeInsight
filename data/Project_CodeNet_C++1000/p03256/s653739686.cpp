#include <bits/stdc++.h>
#define IL inline 
using namespace std; 

const int maxn = 5e5 + 10;
vector<int>edge[maxn];
bool vis[maxn];
int deg[maxn][2];
char s[maxn];

IL int read() {
	char ch = getchar(); int u = 0, f = 1;
	while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
	while (isdigit(ch)) { u = (u << 1) + (u << 3) + ch - 48; ch = getchar(); }
	return u * f;	
}
int main() {
#ifdef Edgration 
	freopen("1.in", "r", stdin); 
#endif
	int n = read(), m = read();
	scanf("%s", s + 1);
	for (int i = 1; i <= m; ++i) {
		int x = read(), y = read();
		edge[x].push_back(y); edge[y].push_back(x);
		deg[x][s[y] == 'A']++; deg[y][s[x] == 'A']++;
	}
	queue<int>q;
	for (int i = 1; i <= n; ++i) if (deg[i][0] == 0 || deg[i][1] == 0) q.push(i), vis[i] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop(); 
		for (int i = 0; i < edge[u].size(); ++i) {
			int v = edge[u][i];
			deg[v][s[u] == 'A']--;
			if (!vis[v] && deg[v][s[u] == 'A'] == 0) {
				vis[v] = 1; q.push(v);
			}
		}
	}
	for (int i = 1; i <= n; ++i) if (!vis[i]) {
		puts("Yes"); return 0;	
	}
	puts("No");
	return 0;	
}