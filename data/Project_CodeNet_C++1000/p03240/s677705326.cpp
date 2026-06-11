#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int n;
	cin >> n;
	int i, j, k, ch, a[101][3] = { 0 };
	for (i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	int f = 0;
	while (a[f][2] == 0)
		f++;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			int h = abs(i - a[f][0]) + abs(j - a[f][1]) + a[f][2];
			int flag = 0;
			for (int k = 0; k < n; k++) {
				int ch = h - abs(i - a[k][0]) - abs(j - a[k][1]);
				if (ch < 0)
					ch = 0;
				if (ch != a[k][2]) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				cout << i << ' ' << j << ' ' << h << endl;
				return 0;
			}
		}
	}
}
