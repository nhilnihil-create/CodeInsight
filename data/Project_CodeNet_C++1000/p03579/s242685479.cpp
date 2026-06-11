#include<iostream>
#include<vector>
using namespace std;

//二部グラフ
long long int n, m;
long long int black = 0;
vector<vector<int>>graph;
vector<int>color;

bool dfs(int v, int c) {
	color[v] = c;
	for (int i = 0; i < graph[v].size(); ++i) {
		if (color[graph[v][i]] == c)return false;//隣の色が同じなら失敗
		if (color[graph[v][i]] == -1) {//まだ塗られていないなら
			if (!dfs(graph[v][i], 1 - c))return false;//if文は()のなかが0のとき実行されない。つまり、これが実行されるのは!dfs=1つまりdfsがfalseを返したとき
		}
	}
	return true;
}

int main() {
	cin >> n >> m;
	graph.resize(n, vector<int>());
	color.resize(n, -1);
	bool judge;
	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		a--; b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	judge = dfs(0, 0);
	if (judge) {
		for (int i = 0; i < n; ++i)if (color[i] == 1)++black;
		cout << black * (n - black) - m << endl;
	}
	else cout << n * (n - 1) / 2 - m << endl;
	return 0;
}