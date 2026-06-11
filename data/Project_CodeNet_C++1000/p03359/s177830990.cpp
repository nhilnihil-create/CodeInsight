#include "bits/stdc++.h"
using namespace std;

int main() {
	int A, B;
	cin >> A >> B;
	if (A <= B) {
		cout << A << endl;
	}
	else {
		cout << A - 1 << endl;
	}
	return 0;
}