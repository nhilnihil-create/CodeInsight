#include<iostream>
#include<algorithm>
using namespace std;

int numbers[300005];

void f(int x, int y, int z) {
	for (int i = 0; i < y; i++) {
		if (i < z) {
			numbers[x + i] = x + y - z + i;
		}
		else {
			numbers[x + i] = x + y - 1 - i;
		}
	}
}

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	bool flag = b > a;
	if (flag) {
		swap(a, b);
	}
	int q, r;
	q = n / b;
	r = n % b;
	if (a < (q + (r != 0)) || a > n + 1 - b) {
		cout << -1 << endl;
		return 0;
	}
	int more = a - (q + (r != 0));
	if (more >= (b - 1)*(q - 1)) {
		f(1, b, 1);
		for (int i = 2; i <= q; i++) {
			f(b*(i - 1) + 1, b, b);
		}
		f(q*b + 1, r, more - (b - 1)*(q - 1) + 1);
	}
	else {
		int x = more / (b - 1);
		for (int i = 1; i <= x; i++) {
			f(b*(i - 1) + 1, b, b);
		}
		f(b*x+1, b , more % (b - 1) + 1);
		for (int i = x + 2; i <= q; i++) {
			f(b*(i - 1) + 1, b, 1);
		}
		f(q*b + 1, r, 1);
	}

	if (flag) {
		for (int i = 1; i <= n; i++) {
			numbers[i] = n + 1 - numbers[i];
		}
	}
	for (int i = 1; i <= n-1; i++) {
		cout << numbers[i] << " ";
	}
	cout << numbers[n] << endl;
}