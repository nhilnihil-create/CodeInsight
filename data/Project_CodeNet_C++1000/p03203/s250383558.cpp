#include <bits/stdc++.h>
using namespace std;
int main() {
	int H, W, N;
	cin >> H >> W >> N;
	vector<set<int>> a(W+1);
	for (int i = 0; i < N; ++ i) {
		int x, y;
		cin >> x >> y;
		a[y].insert(x);
	}
	for (int i = 1; i <= W; ++ i) a[i].insert(H+1);
	int r = H;
	int p = 1;
	for (int j = 1; ; ++ j) {
		r = min(r, *a[j].lower_bound(p) - 1);
		if (j == W) break;
		for (;;) {
			++ p;
			if (!a[j+1].count(p)) break;
		}
		if (p > H) break;
	}
	cout << r << endl;
}
