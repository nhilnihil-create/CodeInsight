#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int h, w;
	cin >> h >> w;
	int a[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> a[i][j];
		}
	}
	vector<vector<int>> b(h, vector<int>(w));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> b[i][j];
		}
	}

	for (int k = 0; k < 10; k++) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
			}
		}
	}
	
	long long ans = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (b[i][j] != -1) {
				ans += a[b[i][j]][1];
			}
		}
	}
	cout << ans << endl;

	return 0;
}