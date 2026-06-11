#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int getMin(int arr[]) {
	int m = 100;
	for (int i = 0; i < 3; i++) {
		m = min(m, arr[i]);
	}
	return m;
}

int main(int argc, char const* argv[]) {
	int c[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &c[i][j]);
		}
	}
	int a[3], b[3];
	a[0] = getMin(c[0]);
	for (int i = 0; i <= a[0]; i++) {
		for (int j = 0; j < 3; j++) {
			b[j] = c[0][j] - i;
		}
		// cout << a[0] << " " << b[0] << " " << b[1] << " " << b[2] << "\n";
		if (c[1][0] - b[0] >= 0 && c[1][0] - b[0] == c[1][1] - b[1] && c[1][1] - b[1] == c[1][2] - b[2]
				&& c[2][0] - b[0] >= 0 && c[2][0] - b[0] == c[2][1] - b[1] && c[2][1] - b[1] == c[2][2] - b[2]) {
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");

	return 0;
}
