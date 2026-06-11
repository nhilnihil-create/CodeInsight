#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int H, W;
	cin >> H >> W;
	vector<vector<int>> a(H, vector<int>(W, -1));
	queue<tuple<int, int, int>> q;
	for (int i = 0; i < H; ++i) {
		string ai; cin >> ai;
		for (int j = 0; j < W; ++j) {
			if (ai[j] == '#') {
				a[i][j] = 0;
				q.push(make_tuple(i, j, 0));
			}
		}
	}
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		int i = get<0>(t);
		int j = get<1>(t);
		int c = get<2>(t);
		if (i > 0 && a[i - 1][j] == -1) {
			a[i - 1][j] = c + 1;
			q.push(make_tuple(i - 1, j, c + 1));
		}
		if (i < H - 1 && a[i + 1][j] == -1) {
			a[i + 1][j] = c + 1;
			q.push(make_tuple(i + 1, j, c + 1));
		}
		if (j > 0 && a[i][j - 1] == -1) {
			a[i][j - 1] = c + 1;
			q.push(make_tuple(i, j - 1, c + 1));
		}
		if (j < W - 1 && a[i][j + 1] == -1) {
			a[i][j + 1] = c + 1;
			q.push(make_tuple(i, j + 1, c + 1));
		}
		if (q.empty())
			cout << c << endl;
	}
	/*
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j)
			cout << a[i][j] << " ";
		cout << endl;
	}
	*/
	return 0;
}