#include<iostream>
#include<algorithm>

using namespace std;

int sum(int a, int b) {
	int t = 0;
	while (a > 0) {
		t += a % 10;
		a /= 10;
	}
	
	while (b > 0) {
		t+= b % 10;
		b /= 10;
	}

	return t;
}
int main() {
	int n;
	cin >> n;


	int mn = 1000000000;

	for (int i = 1; i < n; i++) {
		mn = min(mn, sum(i, n - i));
	}

	cout << mn << endl;

	return 0;
}