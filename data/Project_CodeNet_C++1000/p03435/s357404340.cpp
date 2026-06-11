#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int a[3], b[3], i,j,map[3][3];
	rep(i, 3) {
		rep(j, 3) {
			cin >> map[i][j];
		}
	}
	rep(i, 3) {
		while (min(map[i][0], min(map[i][1], map[i][2])) >= 1) {
			map[i][0]--;
			map[i][1]--;
			map[i][2]--;
		}
	}
	rep(i, 3) {
		while (min(map[0][i], min(map[1][i], map[2][i])) >= 1) {
			map[0][i]--;
			map[1][i]--;
			map[2][i]--;
		}
	}
	rep(i, 3) {
		rep(j, 3) {
			if (map[i][j] != 0) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}