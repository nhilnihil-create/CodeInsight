#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stack>

using namespace std;
typedef long long ll;
using Graph = vector<vector<int>>;


namespace dfs6
{
	Graph graph;
	vector<int> colors;

	bool dfs(int v, int color)
	{
		colors[v] = color;
		//頂点vの連結先を探索する
		for (int nv : graph[v]) {
			//未探索か
			if (colors[nv] == -1) {
				if (!dfs(nv, 1 - color)) {
					return false;
				}
			}
			else {
				//二部グラフでないか
				if (color == colors[nv]) {
					return false;
				}
			}
		}
		return true;
	}
	void exec()
	{
		ll N, M; cin >> N >> M;
		graph.resize(N);
		for (int _ = 0; _ < M;++_) {
			int a, b;cin >> a >> b;--a;--b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		colors.resize(N, -1);
		if (dfs(0, 0)) {
			ll B, W;
			B = count(colors.begin(), colors.end(), 0);
			W = N - B;
			cout << B * W - M << endl;
		}
		else {
			cout << N * (N - 1) / 2 - M << endl;
		}
	}
}

int main()
{
	dfs6::exec();
	/*vector<int> anss;
	for (;;) {
		dfs2::exec();
		if (dfs2::W == 0 || dfs2::H == 0) break;
		anss.push_back(dfs2::ilands);
	}
	for (int i = 0; i < anss.size(); ++i) {
		cout << anss[i] << endl;
	}*/

	return 0;
}
