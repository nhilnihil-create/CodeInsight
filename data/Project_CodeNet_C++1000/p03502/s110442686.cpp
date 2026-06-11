#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, X, S;
	cin >> N;
	X = N;
	while (X > 0) {
		S += X % 10;
		X /= 10;
	}
	
	if (N % S == 0) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}
