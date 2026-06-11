#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 201000
using namespace std;
int n, m, w[N_], v[N_], head, tail, Deg[N_][2];
char p[201000];
vector<int>E[N_][2];
int Q[N_*2];
void Add(int a, int b) {
	if (p[b] == 'A')E[a][0].push_back(b);
	else E[a][1].push_back(b);
}
int main() {
	int i, a, b, j;
	scanf("%d%d", &n, &m);
	scanf("%s", p + 1);
	for (i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		Add(a, b);
		Add(b, a);
	}
	for (i = 1; i <= n; i++) {
		for (j = 0; j < 2; j++) {
			Deg[i][j] = E[i][j].size();
			if (E[i][j].size() == 0 && !v[i]) {
				Q[++tail] = i;
				v[i] = 1;
			}
		}
	}
	while (head < tail) {
		int x = Q[++head];
		int ck = p[x] - 'A';
		for (auto &y : E[x][0]) {
			Deg[y][ck]--;
			if (!Deg[y][ck] && !v[y]) {
				Q[++tail] = y;
				v[y] = 1;
			}
		}
		for (auto &y : E[x][1]) {
			Deg[y][ck]--;
			if (!Deg[y][ck] && !v[y]) {
				Q[++tail] = y;
				v[y] = 1;
			}
		}
	}
	if (tail == n)puts("No");
	else puts("Yes");
}