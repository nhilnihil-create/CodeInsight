#include <bits/stdc++.h>
using namespace std;

int digit(int x) {
	int y = 0;
	while (x != 0) {
		y += x % 10;
		x /= 10;
	}
	return y;
}
int main() {
	int N, min = 1000;
	cin >> N;
	for (int i = 1; i <= N / 2; i++) {
		int j = N - i;
		int X = digit(i) + digit(j);
		if (X < min) min = X;
	}
	cout << min << endl;
}
