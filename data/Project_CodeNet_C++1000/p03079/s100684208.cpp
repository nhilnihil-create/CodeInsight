#include "bits/stdc++.h"
using namespace std;


int main() {

	int A, B, C;
	int flag = 0;

	cin >> A >> B >> C;

	if (A == B && B == C) {
		flag = 1;
	}

	if (flag == 1) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;

}
