#include <iostream>
#include <vector>
using namespace std;

int gcd(int, int);

int main() {

	int N, X;
	cin >> N >> X;
	vector<int> x,from_X;

	int gcd_num = 0;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		x.push_back(tmp);
	}

	for (int i = 0; i < N; i++) {
		from_X.push_back(abs(X - x[i]));
	}

	for (int i = 0; i < N; i++) {
		gcd_num = gcd(gcd_num, from_X[i]);
	}

	cout << gcd_num;
	return 0;
}

int gcd(int a, int b) {
	if (a < b) return gcd(b, a);
	if (b == 0) return a;
	int r;
	while ((r = a % b)) {
		a = b;
		b = r;
	}
	return b;
}

//made by myself