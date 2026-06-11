#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, m, X, Y;
	cin >> n >> m >> X >> Y;
	vector<int> x(n), y(m);
	for (int i = 0; i < n; i++)
		cin >> x[i];
	for (int i = 0; i < m; i++)
		cin >> y[i];
	int zmin, zmax;
	int xmax = -101;
	for (int i = 0; i < n; i++)
		if (xmax < x[i])
			xmax = x[i];
	zmin = max(X + 1, xmax + 1);
	int ymin = 101;
	for (int i = 0; i < m; i++)
		if (ymin > y[i])
			ymin = y[i];
	zmax = min(Y, ymin);
	if (zmax - zmin >= 0)
		cout << "No War" << endl;
	else
		cout << "War" << endl;
	return 0;
}