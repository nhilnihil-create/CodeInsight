#include "bits/stdc++.h"
using namespace std;

int main() {
	int A, B;
	cin >> A >> B;
	if ((1 == A % 2) && (1 == B % 2)) {
		cout << "Odd" << endl;
	}
	else {
		cout << "Even" << endl;
	}
	return 0;
}