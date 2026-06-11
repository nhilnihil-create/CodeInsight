#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> xv(n + 1);
	vector<int> yv(m + 1);
	cin >> xv[0];
	cin >> yv[0];

	int mx = xv[0];
	for (int i = 1; i <= n; ++i) {
		cin >> xv[i];
		mx = max(xv[i], mx);
	}

	int my = yv[0];
	for (int i = 1; i <= m; ++i) {
		cin >> yv[i];
		my = min(yv[i], my);
	}

	if (mx < my) {
		cout << "No War" << endl;
	}
	else {
		cout << "War" << endl;
	}

	return 0;
}