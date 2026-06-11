#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<pair<int, int>>> vt;
int de[100010],indegree[100010];
int visited[100010],update;
void dfs(int here, int par) {
	visited[here] = 1;
	for (int i = 0; i < vt[here].size(); i++)
	{
		int next = vt[here][i].first;
		int ncst = vt[here][i].second;
		if (next == par)continue;
		if (!visited[next]) {
			de[next] = de[here] + ncst;
			dfs(next, here);
		}
		else if (de[next] != de[here] + ncst)
			update = 1;
	}
}
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	vt.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int q, w, e;
		scanf("%d %d %d", &q, &w, &e);
		vt[q].push_back({ w,e });
		indegree[w]++;
	}
	for (int i = 1; i <= n; i++) {
		if(!indegree[i])
			dfs(i, 0);
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i])
			dfs(i, 0);
	}
	if (update)puts("No");
	else puts("Yes");
}