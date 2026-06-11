#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;

namespace dfs3
{
	struct Edge
	{
		int to;
		int weight;
		Edge(int t, int w) : to(t), weight(w) {}
	};
	vector<vector<Edge>> graph;
	int colors[100001];
	int N;

	//偶数:0
	//奇数:1
	bool dfs(int v, int color = 0)
	{
		colors[v] = color;
		for (Edge edge : graph[v]) {
			if ((edge.weight % 2) == 0) {
				//同じ色にする
				if (colors[edge.to] == -1) {
					dfs(edge.to, colors[v]);
				}
				else if (colors[edge.to] != colors[v]) {
					return false;
				}
			}
			else {
				//違う色にする
				if (colors[edge.to] == -1) {
					dfs(edge.to, (colors[v] + 1) % 2);
				}
				else if (colors[edge.to] == colors[v]) {
					return false;
				}
			}
		}
		return true;
	}
	void exec()
	{
		int N; cin >> N;
		graph.resize(N);
		for (int i = 0; i < N - 1; ++i) {
			int from, to, weight;
			cin >> from >> to >> weight;
			--from;--to;
			graph[from].push_back(Edge(to, weight));
			graph[to].push_back(Edge(from, weight));
		}
		for (int i = 0; i < N; ++i) {
			memset(colors, -1, sizeof(colors));
			if (dfs(i)) break;
		}
		for (int i = 0; i < N; ++i) {
			
			cout << colors[i] << endl;
		}
	}
}

int main()
{
	//dfs1::exec();

	/*
	vector<int> anss;
	for (;;) {
		dfs2::exec();
		if (dfs2::W == 0 || dfs2::H == 0) break;
		anss.push_back(dfs2::ilands);
	}
	for (int i = 0; i < anss.size(); ++i) {
		cout << anss[i] << endl;
	}
	*/
	dfs3::exec();
	return 0;
}
