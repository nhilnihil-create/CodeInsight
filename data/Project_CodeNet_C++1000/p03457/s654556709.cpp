#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dist(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
    
	int n; cin >> n;
	vector<int> t(n + 1, 0), x(n + 1, 0), y(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> x[i] >> y[i];
	}
	bool can = true;
	for (int i = 1; i <= n; i++) {
		int dt = t[i] - t[i - 1];
		int ddist = dist(x[i], y[i], x[i - 1], y[i - 1]);
		if (dt < ddist) {
			can = false;
		}
		if ((dt % 2) != (ddist % 2)) {
			can = false;
		}
	}
	if (can) cout << "Yes" << endl;
	else cout << "No" << endl;
    return 0;
}