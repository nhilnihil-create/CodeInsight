#include<iostream>

using namespace std;

int main() {
	int a[3], b[3], c[3][3];
	bool flag = false;

	cin >> c[0][0] >> c[0][1] >> c[0][2];
	cin >> c[1][0] >> c[1][1] >> c[1][2];
	cin >> c[2][0] >> c[2][1] >> c[2][2];

	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			for (int k = 0; k <= 100; k++) {
				a[0] = i;
				a[1] = j;
				a[2] = k;
				b[0] = c[0][0] - a[0];
				b[1] = c[0][1] - a[0];
				b[2] = c[0][2] - a[0];
				if (b[0] >= 0 && b[1] >= 0 && b[2] >= 0) {
					if (c[1][0] == a[1] + b[0] && c[1][1] == a[1] + b[1] && c[1][2] == a[1] + b[2]) {
						if (c[2][0] == a[2] + b[0] && c[2][1] == a[2] + b[1] && c[2][2] == a[2] + b[2]) {
							flag = true;
						}
					}
				}
			}
		}
	}
	if (flag) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}


	return 0;
}