#include "bits/stdc++.h"
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}

int lcm(int x, int y) {
	return x * y / gcd(x, y);
}

int main() {
	int N;
	cin >> N;
	cout << lcm(N,2) << endl;
	return 0;
}
