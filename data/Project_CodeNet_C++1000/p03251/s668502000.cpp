#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, xma, ymi;
	cin >> n >> m >> xma >> ymi;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		xma = max(x, xma);
	}
	for (int i = 0, y; i < m; i++) {
		cin >> y;
		ymi = min(y, ymi);
	}
	cout << (xma < ymi ? "No War" : "War") << endl;
}
