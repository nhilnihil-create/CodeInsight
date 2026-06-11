#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

typedef long long ll;

int Q;

int main() {
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		ll A, B;
		cin >> A >> B;
		if (A > B)swap(A, B);
		if (A == B) {
			cout << (A - 1) * 2 << endl;
		}
		else if (A + 1 == B) {
			cout << (A - 1) * 2 << endl;
		}
		else {
			ll root = sqrt(A * B - 1);
			if (root * root > A * B - 1)root--;
			if (root * (root + 1) < A * B) {
				cout << root * 2 - 1 << endl;
			}
			else {
				cout << root * 2 - 2 << endl;
			}
		}

	}
	return 0;
}