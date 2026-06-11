#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int A, B;
	cin >> A >> B;
	string S;
	cin >> S;
	for (int i = 0; i < A; ++i) {
		if (S[i] < '0' || S[i] > '9') {
			cout << "No" << '\n';
			return 0;
		}
	}
	if (S[A] != '-') {
		cout << "No" << '\n';
		return 0;	
	}
	for (int i = A + 1; i < A + B; ++i) {
		if (S[i] < '0' || S[i] > '9') {
			cout << "No" << '\n';
			return 0;
		}
	}
	cout << "Yes" << '\n';
	
	return 0;
}
