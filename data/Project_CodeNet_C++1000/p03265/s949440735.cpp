#include <bits/stdc++.h>
using namespace std;

int x[2], y[2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (int i = 0; i < 2; i++) cin >> x[i] >> y[i];
	int dx = x[1] - x[0];
	int dy = y[1] - y[0];
	swap(dx, dy);
	dx *= -1;
	cout << x[1] + dx << " " << y[1] + dy << " " << x[0] + dx << " " << y[0] + dy << endl;
	return 0;
}

