#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int64_t solve(int64_t x) {
	x++;
	if (x % 2 == 0) {
		if ((x / 2) % 2 == 1) return 1;
		else return 0;
	}
	else {
		if ((x / 2) % 2 == 1) return x;
		else return --x;
	}
}

int main() {
	int64_t A, B;
	cin >> A >> B;

	int64_t a, b;
	a = solve(A - 1);
	b = solve(B);
	//cout << a << ' ' << b << endl;

	cout << (a ^ b) << endl;
}