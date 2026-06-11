#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int N = 2e5 + 5;
int n, m, cnt[N][2];
char str[N];
bool tag[N], del[N];
vector<int> G[N];
queue<int> Q;
int main() {
	scanf("%d%d%s", &n, &m, str + 1);
	for (int i = 1; i <= n; ++i)
		tag[i] = (str[i] == 'A') ? 1 : 0;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i)
		for (int to : G[i])
			++cnt[i][tag[to]];
	while (Q.size())
		Q.pop();
	for (int i = 1; i <= n; ++i)
		if (!cnt[i][0] || !cnt[i][1])
			Q.push(i), del[i] = 1;
	while (Q.size()) {
		int u = Q.front();
		Q.pop();
		for (int to : G[u]) {
			if (del[to])
				continue ;
			--cnt[to][tag[u]];
			if (!cnt[to][0] || !cnt[to][1]) {
				Q.push(to);
				del[to] = 1;
			}
		}
	}
	bool ans = 0;
	for (int i = 1; i <= n; ++i)
		ans |= !del[i];
	if (ans)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}