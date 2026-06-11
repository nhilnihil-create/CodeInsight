#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, A, B;
	cin >> N >> A >> B;
	if (N != 3) {
		if ((B - A) % 2 == 0) {
			cout << "Alice" << endl;
		}
		else {
			cout << "Borys" << endl;
		}
	}
	else {
		if (A == 1 && B == 3) {
			cout << "Alice" << endl;
		}
		else {
			cout << "Borys" << endl;
		}
	}
}