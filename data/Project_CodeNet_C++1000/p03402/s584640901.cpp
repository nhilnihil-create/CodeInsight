
// D - Grid Components

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

bool grid[100][100];

void print_grid() {
	cout << 100 << " " << 100 << endl;
	for (int i=0; i<100; i++) {
		for (int j=0; j<100; j++) {
			if (grid[i][j]) cout << '#';
			else cout << '.';
		}
		cout << endl;
	}
}

int main() {
	int A, B;
	cin >> A >> B;

	for (int i=0; i<50; i++) {
		for (int j=0; j<100; j++) {
			grid[i][j] = true;
		}
	}

	A--;
	for (int i=0; i<50; i+=2) {
		for (int j=0; j<100; j+=2) {
			if (A == 0) break;

			grid[i][j] = false;
			A--;
		}
	}

	B--;
	for (int i=99; i>=50; i-=2) {
		for (int j=0; j<100; j+=2) {
			if (B == 0) break;

			grid[i][j] = true;
			B--;
		}
	}

	print_grid();

	return 0;
}