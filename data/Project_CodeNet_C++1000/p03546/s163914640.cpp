#include <iostream>
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	int c[10][10];
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			cin >> c[i][j];
	for (int k = 0; k < 10; k++)
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
	int ans = 0;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++) {
			int a;
			cin >> a;
			if (a == -1) continue;
			ans += c[a][1];
		}
	cout << ans << endl;
	return 0;
}