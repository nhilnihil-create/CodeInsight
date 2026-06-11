#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

// 頂点数n, 木g
int n;
vector<vector<int>> g;

// 入力の受け取り
void input() {
	cin >> n;
	g.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		int ai, bi; cin >> ai >> bi;
		g[--ai].push_back(--bi);
		g[bi].push_back(ai);
	}
	return;
}

// sから最も遠い頂点とその距離を求める
pair<int, int> farthest(int s, bool rst = true, int d = 0) {
	static vector<bool> visited;
	if (rst) visited = vector<bool>(n, false);
	visited[s] = true;
	pair<int, int> res = make_pair(s, d);
	for (int nx : g[s]) {
		if (!visited[nx]) {
			pair<int, int> tmp = farthest(nx, false, d + 1);
			if (res.second < tmp.second)
				res = tmp;
		}
	}
	return res;
}

// 木の直径を求める
int diameter() {
	return farthest(farthest(0).first).second;
}

// メイン関数
int main() {
	input();
	int d = diameter();
	if (d % 3 == 1) cout << "Second" << endl;
	else cout << "First" << endl;
	return 0;
}