#include <iostream>
using namespace std;
const int INF = 1001001001;

int main() {
	int h, w;
	cin >> h >> w;
	int c[10][10];
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			cin >> c[j][i];
	int d1[10];
	int used[10];
	fill(d1, d1+10, INF);
	d1[1] = 0;
	fill(used, used+10, false);
	while (true) {
		int v = -1;
		for (int i = 0; i < 10; i++)
			if (!used[i] && (v == -1 || d1[i] < d1[v])) v = i;
		if (v == -1) break;
		used[v] = true;
		for (int i = 0; i < 10; i++) {
			if (d1[i] > d1[v] + c[v][i]) {
				d1[i] = d1[v] + c[v][i];
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++) {
			int a;
			cin >> a;
			if (a == -1) continue;
			ans += d1[a];
		}
	cout << ans << endl;
	return 0;
}