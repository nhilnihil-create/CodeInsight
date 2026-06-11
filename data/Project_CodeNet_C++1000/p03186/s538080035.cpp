#include <bits/stdc++.h>
using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	if (A + B >= C) {
		cout << B + C << endl;
	}
	else if (A + B < C) {
		cout << A + 2 * B + 1 << endl; 
	}
}