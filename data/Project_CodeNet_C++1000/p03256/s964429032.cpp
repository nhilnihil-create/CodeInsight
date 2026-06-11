#include <bits/stdc++.h>
#define MAX_N 200000
using namespace std;
template <class T> inline void read(T &x) {
	x = 0; int c = getchar(), f = 1;
	for (; !isdigit(c); c = getchar()) if (c == 45) f = -1;
	for (; isdigit(c); c = getchar()) (x *= 10) += f*(c-'0');
}
char s[MAX_N+5]; bool mrk[MAX_N+5];
int n, m, c[MAX_N+5], d[MAX_N+5][2];
vector <int> G[MAX_N+5]; queue <int> que;
int main() {
	read(n), read(m), scanf("%s", s+1);
	for (int i = 1; i <= n; i++) c[i] = s[i] == 'B';
	for (int i = 1, u, v; i <= m; i++)
		read(u), read(v), 
		G[u].push_back(v), d[v][c[u]]++, 
		G[v].push_back(u), d[u][c[v]]++;
	for (int i = 1; i <= n; i++)
		if (!d[i][0] || !d[i][1])
			que.push(i), mrk[i] = true;
	while (!que.empty()) {
		int u = que.front(); que.pop();
		for (int v : G[u])
			if (!mrk[v] && !--d[v][c[u]])
				que.push(v), mrk[v] = true;
	}
	for (int i = 1; i <= n; i++)
		if (!mrk[i]) return puts("Yes"), 0;
	return puts("No"), 0;
}