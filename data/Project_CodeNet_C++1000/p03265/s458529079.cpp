#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	int dx = x2 - x1, dy = y1 - y2;
	cout << x2 + dy << ' ' << y2 + dx << ' ';
	cout << x2 + dy - dx << ' ' << y2 + dx + dy << endl;
	return 0;
}