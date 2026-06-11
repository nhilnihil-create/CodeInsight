#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, m, x, y;
	cin >> n >> m >> x >> y;

	int mn = y, mx = x;
	int t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		mx = max(mx, t);
	}
	for (int i = 0; i < m; i++) {
		cin >> t;
		mn = min(mn, t);
	}
	
	if (mx < mn) {
		cout << "No War" << endl;
	}
	else {
		cout << "War" << endl;
	}

	return 0;
}