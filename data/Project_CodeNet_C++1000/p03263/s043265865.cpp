#include <iostream>
#include <vector>
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	vector<vector<int>> a(h, vector<int>(w));
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> a[i][j];

	vector<vector<int>> b(h, vector<int>(w));
	b = a;

	int ans = 0;
	for (int i = 0; i < h; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < w; j++) {
				if (j == w - 1 && b[i][j] % 2 == 1 && i + 1 < h) {
					b[i][j]--;
					b[i + 1][j]++;
					ans++;
				}
				else if (b[i][j] % 2 == 1 && j + 1 < w) {
					b[i][j]--;
					b[i][j + 1]++;
					ans++;
				}
			}
		}
		else {
			for (int j = w - 1; j >= 0; j--) {
				if (j == 0 && b[i][j] % 2 == 1 && i + 1 < h) {
					b[i][j]--;
					b[i + 1][j]++;
					ans++;
				}
				else if (b[i][j] % 2 == 1 && j - 1 >= 0) {
					b[i][j]--;
					b[i][j - 1]++;
					ans++;
				}
			}
		}
	}

	cout << ans << endl;
	
	for (int i = 0; i < h; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < w; j++) {
				if (j == w - 1 && a[i][j] % 2 == 1 && i + 1 < h) {
					a[i][j]--;
					a[i + 1][j]++;
					cout << i + 1 << ' ' << j + 1 << ' ' << i + 2 << ' ' << j + 1 << endl;
				}
				else if (a[i][j] % 2 == 1 && j + 1 < w) {
					a[i][j]--;
					a[i][j + 1]++;
					cout << i + 1 << ' ' << j + 1 << ' ' << i + 1 << ' ' << j + 2 << endl;
				}
			}
		}
		else {
			for (int j = w - 1; j >= 0; j--) {
				if (j == 0 && a[i][j] % 2 == 1 && i + 1 < h) {
					a[i][j]--;
					a[i + 1][j]++;
					cout << i + 1 << ' ' << j + 1 << ' ' << i + 2 << ' ' << j + 1 << endl;
				}
				else if (a[i][j] % 2 == 1 && j - 1 >= 0) {
					a[i][j]--;
					a[i][j - 1]++;
					cout << i + 1 << ' ' << j + 1 << ' ' << i + 1 << ' ' << j << endl;
				}
			}
		}
	}
	return 0;
}