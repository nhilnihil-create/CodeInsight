#include <vector>
#include <iostream>
using namespace std;
const int depth = 13;
struct edge {
	int a, b, c;
};
int main() {
	int L;
	cin >> L;
	vector<edge> ans;
	int mul = 1;
	for (int i = 0; i < depth - 1; ++i) {
		ans.push_back(edge{ i, i + 1, mul * 0 });
		ans.push_back(edge{ i, i + 1, mul * 1 });
		ans.push_back(edge{ i, i + 1, mul * 2 });
		mul *= 3;
	}
	int sum = 0;
	for (int i = depth - 1; i >= 0; --i) {
		for (int j = 0; j < L / mul % 3; ++j) {
			ans.push_back(edge{ i, depth, sum });
			sum += mul;
		}
		mul /= 3;
	}
	cout << depth + 1 << ' ' << ans.size() << endl;
	for (edge e : ans) {
		cout << e.a + 1 << ' ' << e.b + 1 << ' ' << e.c << endl;
	}
	return 0;
}