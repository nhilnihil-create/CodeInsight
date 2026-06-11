#include <iostream>
#include <vector>
using namespace std;

struct T
{
	int x1, x2, x3, x4;
};

int main() {
	int h, w;
	cin >> h >> w;
	int a[h][w];
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];
		}
	}
	vector<T> ans;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w-1; j++) {
			if (a[i][j] & 1) {
				a[i][j]--;
				a[i][j+1]++;
				ans.push_back({i+1, j+1, i+1, j+2});
			}
		}
	}
	for (int i = 0; i < h-1; i++) {
		int j = w-1;
		if (a[i][j] & 1) {
			a[i][j]--;
			a[i+1][j]++;
			ans.push_back({i+1, j+1, i+2, j+1});
		}
	}
	cout << ans.size() << endl;
	for (T e : ans) {
		cout << e.x1 << ' ' << e.x2 << ' ' << e.x3 << ' ' << e.x4 << endl;
	}
	return 0;
}