#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int k = 50;

int a, b;
bool grid[N][N];

void paintWhite() {
	for (int i = 1; i <= k - 1; i += 2) {
		for (int j = 1; j <= 2 * k; j += 2) {
			if (a == 0) break;
			grid[i][j] = 0;
			a--;
		}
	}
}

void paintBlack() {
	for (int i = 2 * k; i >= k + 2; i -= 2) {
		for (int j = 1; j <= 2 * k; j += 2) {
			if (b == 0) break;
			grid[i][j] = 1;
			b--;
		}
	}
}

int main() {
	//freopen(".inp", "r", stdin); freopen(".out", "w", stdout);
	scanf("%d %d", &a, &b);
	a--; b--;
	printf("%d %d\n", 2 * k, 2 * k);
	for (int i = k - 1; i >= 1; i--) 
		for (int j = 1; j <= 2 * k; j++) grid[i][j] = 1;
	paintBlack();
	paintWhite();
	for (int i = 1; i <= 2 * k; i++) {
		for (int j = 1; j <= 2 * k; j++) {
			(grid[i][j] == 1) ? putchar('#') : putchar('.');
		}
		putchar('\n');
	}
	return 0;
}