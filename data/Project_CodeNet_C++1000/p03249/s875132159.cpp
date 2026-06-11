#include<iostream>
#include<cstdint>
#include<algorithm>
using namespace std;

const int MAX = 100000;

typedef struct node {
	int id;
	int64_t num;
	int edge;
	int height;
	bool operator<(const node& r) const {
		return num < r.num;
	}
} Node;

int main() {
	int N;
	static Node node[MAX];
	cin >> N;
	for (int i = 0;i < N;++ i) {
		cin >> node[i].num;
		node[i].id = i + 1;
		node[i].height = 1;
	}
	sort(node, node + N);
	
	int64_t sum = 0; // 1からの距離
	for (int i = N - 1;i > 0;-- i) { // 大きい数字から確定させる
		int min = 0, max = i;
		int64_t check = node[i].num - N + (node[i].height << 1);
		for (int mid = max >> 1;max - min > 1;mid = min + (max - min >> 1)) {
			if (node[mid].num > check) max = mid;
			else min = mid;
		}
		if (node[min].num != check) { // 繋げる辺が存在しなかった
			cout << -1;
			return 0;
		}
		node[i].edge = min;
		node[min].height += node[i].height;
		sum += node[i].height;
	}
	
	if (sum != node[0].num) {
		cout << -1;
		return 0;
	}
	for (int i = N - 1;i > 0;-- i) {
		cout << node[i].id << " " << node[node[i].edge].id << endl;
	}
	return 0;
}
/*
31536000のコメント解説欄
ここテンプレで用意してるから、A問題とかだとこの先空欄の危険あり
また、コンテスト後に https://31536000.hatenablog.com/ で解説していると思うので、良かったら読んでねー

解説AC
数字の大きい方の頂点から確定させることを考える
この時、この頂点から繋ぐ辺は、自分の数-N+(現時点の自分の属する木の高さ*2)となることが数学的に証明できる(解説放送参照)
ということは二分探索していけばO(NlogN)で判定と構築ができるわけだ
最後に本当に正しいか確認だけして、問題ないなら構築完了
*/