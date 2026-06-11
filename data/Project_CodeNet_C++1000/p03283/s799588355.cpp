#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, M, Q, L, R, p, q;
	cin >> N >> M >> Q;
	vector<vector<int>> a(N);
	for (int i = 0; i < M; i++) {
		cin >> L >> R;
		L--;
		R--;
		a[L].push_back(R);
	}
	for (vector<int>& i : a) sort(i.begin(), i.end());
	for (int i = 0; i < Q; i++) {
		cin >> p >> q;
		p--;
		q--;
		int b = 0;
		for (int j = p; j <= q; j++) b += upper_bound(a[j].begin(), a[j].end(), q) - a[j].begin();
		cout << b << endl;
	}
}