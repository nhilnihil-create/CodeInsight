#include <functional>
#include <iostream>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	static int p[100'001];
	for(int i = 1; i <= N; i++) {
		cin >> p[i];
	}

	// Union-Find木！！！！　好き！！
	static int parent[100'001];
	for(int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	function<int(int)> root = [&](int a) {
		if(a == parent[a]) {
			return a;
		}
		return parent[a] = root(parent[a]);
	};

	const auto unite = [&](int a, int b) {
		if(root(a) != root(b)) {
			parent[root(a)] = root(b);
		}
	};

	for(int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;

		unite(x, y);
	}

	int result = 0;
	for(int i = 1; i <= N; i++) {
		if(root(p[i]) == root(i)) {
			result++;
		}
	}

	cout << result << endl;

	return 0;
}
