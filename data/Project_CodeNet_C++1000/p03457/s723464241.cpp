#include <bits/stdc++.h>
using namespace std;

#define MAX 100000

int main() {
	int N;
	cin >> N;
	int t[MAX + 1], x[MAX + 1], y[MAX + 1];
	t[0] = 0;
	x[0] = 0;
	y[0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> t[i] >> x[i] >> y[i];
	}
	bool flg = true;
	for (int i = 1; i <= N; i++) {
		int dt = t[i] - t[i - 1];
		int dx = abs(x[i] - x[i - 1]);
		int dy = abs(y[i] - y[i - 1]);
		if (dx + dy > dt || (dx + dy) % 2 != dt % 2) {
			flg = false;
		}
	}
	cout << (flg ? "Yes" : "No") << endl;
	return 0;
}
