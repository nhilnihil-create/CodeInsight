#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 2e5 + 10;
bool a[MAXN], dl[MAXN];
int n, m, deg[MAXN][2];
vector<int> Mat[MAXN];
queue<int> del;

void ers(int v) {
	for (int i = 0; i < Mat[v].size(); i++) {
		if (dl[Mat[v][i]])
			continue;
		deg[Mat[v][i]][a[v]]--;
		if (deg[Mat[v][i]][0] == 0 || deg[Mat[v][i]][1] == 0)
			del.push(Mat[v][i]), dl[Mat[v][i]] = true;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		char tmp;
		cin >> tmp;
		a[i] = (tmp == 'A');
	}
	for (int i = 0; i < m; i++) {
		int v, u;
		cin >> v >> u;
		Mat[u].push_back(v);
		Mat[v].push_back(u);
		deg[u][a[v]]++;
		deg[v][a[u]]++;
	}
	for (int i = 1; i <= n; i++)
		if (deg[i][0] == 0 || deg[i][1] == 0)
			del.push(i), dl[i] = true;
	while (!del.empty()) {
		ers(del.front());
		del.pop();
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans += !dl[i];
	if (ans)
		cout << "Yes";
	else
		cout << "No";
}