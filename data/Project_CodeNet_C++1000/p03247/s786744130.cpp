#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int o = 2;
	char c[] = "DLRU";
	stringstream ss;
	long e[44];
	for (int i = 0; i < n; i++) {
		long x, y;
		cin >> x >> y;
		if (o < 2 && o^abs(x + y) & 1) {
			cout << -1 << endl;
			return 0;
		}
		o = abs(x + y) & 1;
		long a = 0, b = o ? 1 - (1l << 40) : -(1l << 39);
		for (int j = 0; j < 39; j++)
			e[j] = 1l << 38 + o - j;
		e[39] = 1;
		for (int j = 0; j < 40; j++) {
			long d = e[j];
			int w = 0;
			if (y - x >= b - a + d * 2 && y + x >= b + a + d * 2)
				w = 3, b += d * 2;
			else if (y - x >= b - a && y + x >= b + a + d * 2)
				w = 2, a += d, b += d;
			else if (y - x >= b - a + d * 2 && y + x >= b + a)
				w = 1, a -= d, b += d;
			ss << c[w];
		}
		ss << '\n';
	}
	cout << 40 << '\n';
	for (int i = 0; i < 40; i++)
		cout << e[i] << ' ';
	cout << '\n' << ss.str() << flush;
	return 0;
}
