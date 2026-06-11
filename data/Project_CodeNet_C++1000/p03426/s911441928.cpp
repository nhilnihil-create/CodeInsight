#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int h, w, d;
	cin >> h >> w >> d;
	vector<int> x(h * w + 1), y(h * w + 1);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			int a;
			cin >> a;
			x[a] = i;
			y[a] = j;
		}
	}

	vector<int> cost(h * w + 1);
	for (int i = d + 1; i <= h * w; i++) {
		cost[i] = cost[i - d] + abs(x[i] - x[i - d]) + abs(y[i] - y[i - d]);
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;

		cout << cost[r] - cost[l] << endl;
	}

	return 0;
}