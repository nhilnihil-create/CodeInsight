// ABC075A - 

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

int main() {
	int A, B, C;
	cin >> A >> B >> C;

	if (A == B) {
		cout << C << endl;
	} else if (B == C) {
		cout << A << endl;
	} else {
		cout << B << endl;
	}

	return 0;
}
