#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int MAX = 200000;

struct Node {
	int n;
	bool isExist; // その頂点をまだ消していないか否か
	vector<int> edge; // 繋がっている頂点
	pair<int, int> node; // 繋がっている'A'と'B'の個数
};

int main() {
	int N, M, a, b;
	string s;
	cin >> N >> M >> s;
	static Node node[MAX];
	for (int i = 0;i < N;++ i) {
		node[i].node = make_pair(0, 0);
		node[i].n = i;
		node[i].isExist = true;
	}
	for (int i = 0;i < M;++ i) {
		cin >> a >> b;
		-- a; -- b;
		node[a].edge.push_back(b);
		node[b].edge.push_back(a);
		s[a] == 'A' ? ++ node[b].node.first : ++ node[b].node.second;
		s[b] == 'A' ? ++ node[a].node.first : ++ node[a].node.second;
	}
	queue<int> que; // 削除する頂点
	for (int i = 0;i < N;++ i) {
		if (node[i].node.first == 0 || node[i].node.second == 0) que.push(i);
	}
	int tmp;
	int del = 0; // 削除した頂点の数
	while (!que.empty()) {
		tmp = que.front();
		que.pop();
		if (!node[tmp].isExist) continue; // 既に削除済み頂点なら無視(BFSなら必ず入れるコードですね)
		node[tmp].isExist = false;
		++ del;
		for (int i = 0, l = node[tmp].edge.size();i < l;++ i) {
			if (!node[node[tmp].edge[i]].isExist) continue;
			s[node[tmp].n] == 'A' ? -- node[node[tmp].edge[i]].node.first : -- node[node[tmp].edge[i]].node.second;
			if (node[node[tmp].edge[i]].node.first == 0 || node[node[tmp].edge[i]].node.second == 0) que.push(node[tmp].edge[i]); // 新しく削除する点
		}
	}
	if (del == N) cout << "No";
	else cout << "Yes";
	return 0;
}
/*
31536000のコメント解説欄
ここテンプレで用意してるから、A問題とかだとこの先空欄の危険あり
また、コンテスト後に https://31536000.hatenablog.com/ で解説していると思うので、良かったら読んでねー

解説AC
'A'と'B'の両方に同時に繋がっていない辺を消していくことを繰り返すと解ける
ここで、消した頂点の周囲の頂点以外は繋がってるかの情報が更新されないことを考えると、BFSすれば解ける

*/