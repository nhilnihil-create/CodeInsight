#include "bits/stdc++.h"
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int x = a + b;
	int y = a * b;
	if (15 == x) {
		cout << "+" << endl;
	}
	else if (15 == y) {
		cout << "*" << endl;
	}
	else {
		cout << "x" << endl;
	}
	return 0;
}