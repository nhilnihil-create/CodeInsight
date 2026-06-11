#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector <int> G[1000006];
int dis, t;
void dfs(int u, int f, int d){
	if (d > dis)
		dis = d, t = u;
	for (int i = 0; i < G[u].size(); ++ i){
		int v = G[u][i];
		if (v != f)
			dfs(v, u, d + 1);
	}
}
int main(){
	int n;
	cin >> n;
	for (int i = 1; i < n; ++ i){
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, 0, 1);
	dis = 0;
	dfs(t, 0, 1);
	cout << (dis % 3 == 2 ? "Second" : "First") << endl;
}
