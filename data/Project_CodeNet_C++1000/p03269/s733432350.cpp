#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int V = 20;
struct edge {
	int a, b, c;
};
int main() {
	int N;
	cin >> N;
	vector<edge> ans;
	for (int i = 0; i < V - 2; ++i) {
		if (N % 2 == 1) {
			ans.push_back(edge{ i, V - 1, N - 1 });
			--N;
		}
		if (N != 0) {
			ans.push_back(edge{ i, i + 1, 0 });
			ans.push_back(edge{ i, i + 1, N / 2 });
			N /= 2;
		}
	}
	for (int i = 0; i < N; ++i) {
		ans.push_back(edge{ V - 2, V - 1, i });
	}
	cout << V << ' ' << ans.size() << endl;
	for (edge e : ans) {
		cout << e.a + 1 << ' ' << e.b + 1 << ' ' << e.c << endl;
	}
	return 0;
}