#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int h, w;
	cin >> h >> w;
	vector<vector<int>> a(h, vector<int>(w));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];
		}
	}

	vector<int> x, y, x_, y_;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w - 1; j++) {
			if (a[i][j] % 2 == 1) {
				x.push_back(i + 1);
				y.push_back(j + 1);
				x_.push_back(i + 1);
				y_.push_back(j + 2);
				a[i][j + 1]++;
			}
		}
		if (i < h - 1 && a[i][w - 1] % 2 == 1) {
			x.push_back(i + 1);
			y.push_back(w);
			x_.push_back(i + 2);
			y_.push_back(w);
			a[i + 1][w - 1]++;
		}
	}

	cout << x.size() << endl;
	for (int i = 0; i < x.size(); i++) {
		cout << x[i] << " " << y[i] << " " << x_[i] << " " << y_[i] << endl;
	}

	return 0;
}